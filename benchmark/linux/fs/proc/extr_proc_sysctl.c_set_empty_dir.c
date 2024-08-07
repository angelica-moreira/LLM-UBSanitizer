#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_1__* ctl_table; } ;
struct ctl_dir {TYPE_2__ header; } ;
struct TYPE_3__ {int /*<<< orphan*/  child; } ;

/* Variables and functions */
 int /*<<< orphan*/  sysctl_mount_point ; 

__attribute__((used)) static void set_empty_dir(struct ctl_dir *dir)
{
	dir->header.ctl_table[0].child = sysctl_mount_point;
}