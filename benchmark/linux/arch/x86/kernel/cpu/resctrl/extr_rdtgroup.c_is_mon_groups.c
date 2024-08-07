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
struct kernfs_node {char const* name; } ;

/* Variables and functions */
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static bool is_mon_groups(struct kernfs_node *kn, const char *name)
{
	return (!strcmp(kn->name, "mon_groups") &&
		strcmp(name, "mon_groups"));
}