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
struct dt_info {int /*<<< orphan*/  dt; } ;

/* Variables and functions */
 int /*<<< orphan*/  sort_node (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sort_reserve_entries (struct dt_info*) ; 

void sort_tree(struct dt_info *dti)
{
	sort_reserve_entries(dti);
	sort_node(dti->dt);
}