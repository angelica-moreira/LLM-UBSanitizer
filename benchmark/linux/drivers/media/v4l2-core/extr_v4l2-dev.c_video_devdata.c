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
struct video_device {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  file_inode (struct file*) ; 
 size_t iminor (int /*<<< orphan*/ ) ; 
 struct video_device** video_devices ; 

struct video_device *video_devdata(struct file *file)
{
	return video_devices[iminor(file_inode(file))];
}