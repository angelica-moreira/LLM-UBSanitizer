#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int (* pid_filter_ctrl ) (int /*<<< orphan*/ ,int) ;} ;
struct state {TYPE_1__ ops; } ;
struct dvb_usb_adapter {int /*<<< orphan*/ * fe; } ;

/* Variables and functions */
 struct state* adap_to_priv (struct dvb_usb_adapter*) ; 
 int stub1 (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int af9035_pid_filter_ctrl(struct dvb_usb_adapter *adap, int onoff)
{
	struct state *state = adap_to_priv(adap);

	return state->ops.pid_filter_ctrl(adap->fe[0], onoff);
}