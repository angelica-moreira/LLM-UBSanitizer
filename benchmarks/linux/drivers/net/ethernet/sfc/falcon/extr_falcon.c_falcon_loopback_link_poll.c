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
struct ef4_link_state {int fd; int up; int speed; int /*<<< orphan*/  fc; } ;
struct ef4_nic {struct ef4_link_state link_state; int /*<<< orphan*/  wanted_fc; int /*<<< orphan*/  mac_lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOOPBACK_INTERNAL (struct ef4_nic*) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  ef4_link_state_equal (struct ef4_link_state*,struct ef4_link_state*) ; 
 int /*<<< orphan*/  mutex_is_locked (int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool falcon_loopback_link_poll(struct ef4_nic *efx)
{
	struct ef4_link_state old_state = efx->link_state;

	WARN_ON(!mutex_is_locked(&efx->mac_lock));
	WARN_ON(!LOOPBACK_INTERNAL(efx));

	efx->link_state.fd = true;
	efx->link_state.fc = efx->wanted_fc;
	efx->link_state.up = true;
	efx->link_state.speed = 10000;

	return !ef4_link_state_equal(&efx->link_state, &old_state);
}