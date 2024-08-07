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
struct drm_device {int /*<<< orphan*/ * dev_private; } ;
typedef  int /*<<< orphan*/  drm_via_private_t ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  via_wait_idle (int /*<<< orphan*/ *) ; 

int via_driver_dma_quiescent(struct drm_device *dev)
{
	drm_via_private_t *dev_priv = dev->dev_private;

	if (!via_wait_idle(dev_priv))
		return -EBUSY;
	return 0;
}