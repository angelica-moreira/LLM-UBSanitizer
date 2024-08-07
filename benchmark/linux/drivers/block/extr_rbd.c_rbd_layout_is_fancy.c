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
struct ceph_file_layout {scalar_t__ stripe_unit; scalar_t__ object_size; } ;

/* Variables and functions */

__attribute__((used)) static bool rbd_layout_is_fancy(struct ceph_file_layout *l)
{
	return l->stripe_unit != l->object_size;
}