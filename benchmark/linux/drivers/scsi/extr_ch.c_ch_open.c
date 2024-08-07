#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct inode {int dummy; } ;
struct file {TYPE_1__* private_data; } ;
struct TYPE_3__ {int /*<<< orphan*/  ref; int /*<<< orphan*/  device; } ;
typedef  TYPE_1__ scsi_changer ;

/* Variables and functions */
 int ENXIO ; 
 int /*<<< orphan*/  ch_index_idr ; 
 int /*<<< orphan*/  ch_index_lock ; 
 int /*<<< orphan*/  ch_mutex ; 
 TYPE_1__* idr_find (int /*<<< orphan*/ *,int) ; 
 int iminor (struct inode*) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ scsi_device_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
ch_open(struct inode *inode, struct file *file)
{
	scsi_changer *ch;
	int minor = iminor(inode);

	mutex_lock(&ch_mutex);
	spin_lock(&ch_index_lock);
	ch = idr_find(&ch_index_idr, minor);

	if (NULL == ch || scsi_device_get(ch->device)) {
		spin_unlock(&ch_index_lock);
		mutex_unlock(&ch_mutex);
		return -ENXIO;
	}
	kref_get(&ch->ref);
	spin_unlock(&ch_index_lock);

	file->private_data = ch;
	mutex_unlock(&ch_mutex);
	return 0;
}