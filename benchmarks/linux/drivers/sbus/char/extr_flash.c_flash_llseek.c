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
struct file {long long f_pos; } ;
struct TYPE_2__ {long long read_size; } ;

/* Variables and functions */
 long long EINVAL ; 
 TYPE_1__ flash ; 
 int /*<<< orphan*/  flash_mutex ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static long long
flash_llseek(struct file *file, long long offset, int origin)
{
	mutex_lock(&flash_mutex);
	switch (origin) {
		case 0:
			file->f_pos = offset;
			break;
		case 1:
			file->f_pos += offset;
			if (file->f_pos > flash.read_size)
				file->f_pos = flash.read_size;
			break;
		case 2:
			file->f_pos = flash.read_size;
			break;
		default:
			mutex_unlock(&flash_mutex);
			return -EINVAL;
	}
	mutex_unlock(&flash_mutex);
	return file->f_pos;
}