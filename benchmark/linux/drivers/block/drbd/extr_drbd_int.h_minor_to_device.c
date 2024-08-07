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
struct drbd_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  drbd_devices ; 
 scalar_t__ idr_find (int /*<<< orphan*/ *,unsigned int) ; 

__attribute__((used)) static inline struct drbd_device *minor_to_device(unsigned int minor)
{
	return (struct drbd_device *)idr_find(&drbd_devices, minor);
}