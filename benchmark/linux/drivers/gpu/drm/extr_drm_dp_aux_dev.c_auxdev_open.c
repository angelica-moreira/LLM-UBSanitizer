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
struct inode {int dummy; } ;
struct file {struct drm_dp_aux_dev* private_data; } ;
struct drm_dp_aux_dev {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 struct drm_dp_aux_dev* drm_dp_aux_dev_get_by_minor (unsigned int) ; 
 unsigned int iminor (struct inode*) ; 

__attribute__((used)) static int auxdev_open(struct inode *inode, struct file *file)
{
	unsigned int minor = iminor(inode);
	struct drm_dp_aux_dev *aux_dev;

	aux_dev = drm_dp_aux_dev_get_by_minor(minor);
	if (!aux_dev)
		return -ENODEV;

	file->private_data = aux_dev;
	return 0;
}