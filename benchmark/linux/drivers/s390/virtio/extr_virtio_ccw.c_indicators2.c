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
struct virtio_ccw_device {TYPE_1__* dma_area; } ;
struct TYPE_2__ {unsigned long indicators2; } ;

/* Variables and functions */

__attribute__((used)) static inline unsigned long *indicators2(struct virtio_ccw_device *vcdev)
{
	return &vcdev->dma_area->indicators2;
}