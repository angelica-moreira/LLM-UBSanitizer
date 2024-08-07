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
struct device {int dummy; } ;
struct ap_matrix_dev {int dummy; } ;

/* Variables and functions */
 struct ap_matrix_dev* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  kfree (struct ap_matrix_dev*) ; 

__attribute__((used)) static void vfio_ap_matrix_dev_release(struct device *dev)
{
	struct ap_matrix_dev *matrix_dev = dev_get_drvdata(dev);

	kfree(matrix_dev);
}