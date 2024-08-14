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
struct mddev {int changed; } ;
struct gendisk {struct mddev* private_data; } ;

/* Variables and functions */

__attribute__((used)) static int md_media_changed(struct gendisk *disk)
{
	struct mddev *mddev = disk->private_data;

	return mddev->changed;
}