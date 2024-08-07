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
struct path {int dummy; } ;

/* Variables and functions */
 int tomoyo_mount_permission (char const*,struct path const*,char const*,unsigned long,void*) ; 

__attribute__((used)) static int tomoyo_sb_mount(const char *dev_name, const struct path *path,
			   const char *type, unsigned long flags, void *data)
{
	return tomoyo_mount_permission(dev_name, path, type, flags, data);
}