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
struct c4iw_ep_common {int state; int /*<<< orphan*/  mutex; } ;
typedef  enum c4iw_ep_state { ____Placeholder_c4iw_ep_state } c4iw_ep_state ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static enum c4iw_ep_state state_read(struct c4iw_ep_common *epc)
{
	enum c4iw_ep_state state;

	mutex_lock(&epc->mutex);
	state = epc->state;
	mutex_unlock(&epc->mutex);
	return state;
}