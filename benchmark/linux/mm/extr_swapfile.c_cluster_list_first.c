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
struct swap_cluster_list {int /*<<< orphan*/  head; } ;

/* Variables and functions */
 unsigned int cluster_next (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline unsigned int cluster_list_first(struct swap_cluster_list *list)
{
	return cluster_next(&list->head);
}