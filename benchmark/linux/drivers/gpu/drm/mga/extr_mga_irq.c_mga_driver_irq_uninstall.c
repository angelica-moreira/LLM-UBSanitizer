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
struct drm_device {int irq_enabled; scalar_t__ dev_private; } ;
typedef  int /*<<< orphan*/  drm_mga_private_t ;

/* Variables and functions */
 int /*<<< orphan*/  MGA_IEN ; 
 int /*<<< orphan*/  MGA_WRITE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void mga_driver_irq_uninstall(struct drm_device *dev)
{
	drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;
	if (!dev_priv)
		return;

	/* Disable *all* interrupts */
	MGA_WRITE(MGA_IEN, 0);

	dev->irq_enabled = false;
}