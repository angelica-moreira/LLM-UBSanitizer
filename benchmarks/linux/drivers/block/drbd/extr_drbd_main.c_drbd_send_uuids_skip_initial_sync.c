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
struct drbd_peer_device {int dummy; } ;

/* Variables and functions */
 int _drbd_send_uuids (struct drbd_peer_device*,int) ; 

int drbd_send_uuids_skip_initial_sync(struct drbd_peer_device *peer_device)
{
	return _drbd_send_uuids(peer_device, 8);
}