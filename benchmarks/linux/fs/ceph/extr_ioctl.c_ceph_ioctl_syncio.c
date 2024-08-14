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
struct file {struct ceph_file_info* private_data; } ;
struct ceph_file_info {int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  CEPH_F_SYNC ; 

__attribute__((used)) static long ceph_ioctl_syncio(struct file *file)
{
	struct ceph_file_info *fi = file->private_data;

	fi->flags |= CEPH_F_SYNC;
	return 0;
}