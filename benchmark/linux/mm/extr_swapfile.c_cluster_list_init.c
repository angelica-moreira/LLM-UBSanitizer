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
struct swap_cluster_list {int /*<<< orphan*/  tail; int /*<<< orphan*/  head; } ;

/* Variables and functions */
 int /*<<< orphan*/  cluster_set_null (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void cluster_list_init(struct swap_cluster_list *list)
{
	cluster_set_null(&list->head);
	cluster_set_null(&list->tail);
}