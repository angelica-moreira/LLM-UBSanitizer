#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {scalar_t__ cu_type; scalar_t__ cu_model; scalar_t__ dev_type; scalar_t__ dev_model; } ;
struct ccw_device {TYPE_1__* private; TYPE_2__ id; } ;
struct TYPE_7__ {scalar_t__ cu_type; scalar_t__ cu_model; scalar_t__ dev_type; scalar_t__ dev_model; } ;
struct TYPE_8__ {TYPE_3__ senseid; } ;
struct TYPE_5__ {TYPE_4__* dma_area; } ;

/* Variables and functions */

int ccw_device_test_sense_data(struct ccw_device *cdev)
{
	return cdev->id.cu_type ==
		cdev->private->dma_area->senseid.cu_type &&
		cdev->id.cu_model ==
		cdev->private->dma_area->senseid.cu_model &&
		cdev->id.dev_type ==
		cdev->private->dma_area->senseid.dev_type &&
		cdev->id.dev_model ==
		cdev->private->dma_area->senseid.dev_model;
}