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
typedef  scalar_t__ u32 ;
struct object_info {scalar_t__ indaddr; } ;
struct adfs_dir {int dummy; } ;

/* Variables and functions */
 int ADFS_NUM_DIR_ENTRIES ; 
 int ENOENT ; 
 int /*<<< orphan*/  __adfs_dir_get (struct adfs_dir*,int,struct object_info*) ; 

__attribute__((used)) static int adfs_dir_find_entry(struct adfs_dir *dir, u32 indaddr)
{
	int pos, ret;

	ret = -ENOENT;

	for (pos = 5; pos < ADFS_NUM_DIR_ENTRIES * 26 + 5; pos += 26) {
		struct object_info obj;

		if (!__adfs_dir_get(dir, pos, &obj))
			break;

		if (obj.indaddr == indaddr) {
			ret = pos;
			break;
		}
	}

	return ret;
}