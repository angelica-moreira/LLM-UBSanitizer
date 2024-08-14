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
struct page {int dummy; } ;

/* Variables and functions */
 int HPAGE_PMD_NR ; 
 scalar_t__ PageTransHuge (struct page*) ; 
 int /*<<< orphan*/  remove_migration_ptes (struct page*,struct page*,int) ; 

__attribute__((used)) static void remap_page(struct page *page)
{
	int i;
	if (PageTransHuge(page)) {
		remove_migration_ptes(page, page, true);
	} else {
		for (i = 0; i < HPAGE_PMD_NR; i++)
			remove_migration_ptes(page + i, page + i, true);
	}
}