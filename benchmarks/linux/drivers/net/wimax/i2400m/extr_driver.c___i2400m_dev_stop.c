#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct wimax_dev {int dummy; } ;
struct i2400m {int /*<<< orphan*/  work_queue; int /*<<< orphan*/  (* bus_dev_stop ) (struct i2400m*) ;scalar_t__ ready; int /*<<< orphan*/  msg_completion; struct wimax_dev wimax_dev; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  EL3RST ; 
 int /*<<< orphan*/  WIMAX_ST_DOWN ; 
 int /*<<< orphan*/  __WIMAX_ST_QUIESCING ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  d_fnend (int,struct device*,char*,struct i2400m*) ; 
 int /*<<< orphan*/  d_fnstart (int,struct device*,char*,struct i2400m*) ; 
 int /*<<< orphan*/  destroy_workqueue (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  flush_workqueue (int /*<<< orphan*/ ) ; 
 struct device* i2400m_dev (struct i2400m*) ; 
 int /*<<< orphan*/  i2400m_dev_shutdown (struct i2400m*) ; 
 int /*<<< orphan*/  i2400m_msg_to_dev_cancel_wait (struct i2400m*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2400m_net_wake_stop (struct i2400m*) ; 
 int /*<<< orphan*/  i2400m_rx_release (struct i2400m*) ; 
 int /*<<< orphan*/  i2400m_tx_release (struct i2400m*) ; 
 int /*<<< orphan*/  stub1 (struct i2400m*) ; 
 int /*<<< orphan*/  wimax_state_change (struct wimax_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wmb () ; 

__attribute__((used)) static
void __i2400m_dev_stop(struct i2400m *i2400m)
{
	struct wimax_dev *wimax_dev = &i2400m->wimax_dev;
	struct device *dev = i2400m_dev(i2400m);

	d_fnstart(3, dev, "(i2400m %p)\n", i2400m);
	wimax_state_change(wimax_dev, __WIMAX_ST_QUIESCING);
	i2400m_msg_to_dev_cancel_wait(i2400m, -EL3RST);
	complete(&i2400m->msg_completion);
	i2400m_net_wake_stop(i2400m);
	i2400m_dev_shutdown(i2400m);
	/*
	 * Make sure no report hooks are running *before* we stop the
	 * communication infrastructure with the device.
	 */
	i2400m->ready = 0;	/* nobody can queue work anymore */
	wmb();		/* see i2400m->ready's documentation  */
	flush_workqueue(i2400m->work_queue);

	if (i2400m->bus_dev_stop)
		i2400m->bus_dev_stop(i2400m);
	destroy_workqueue(i2400m->work_queue);
	i2400m_rx_release(i2400m);
	i2400m_tx_release(i2400m);
	wimax_state_change(wimax_dev, WIMAX_ST_DOWN);
	d_fnend(3, dev, "(i2400m %p) = 0\n", i2400m);
}