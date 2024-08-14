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
struct vme_bridge {struct fake_driver* driver_priv; } ;
struct fake_driver {int /*<<< orphan*/  crcsr_kernel; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void fake_crcsr_exit(struct vme_bridge *fake_bridge)
{
	struct fake_driver *bridge;

	bridge = fake_bridge->driver_priv;

	kfree(bridge->crcsr_kernel);
}