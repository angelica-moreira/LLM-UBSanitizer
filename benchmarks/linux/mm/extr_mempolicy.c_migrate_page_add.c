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
struct list_head {int dummy; } ;

/* Variables and functions */
 int EIO ; 

__attribute__((used)) static int migrate_page_add(struct page *page, struct list_head *pagelist,
				unsigned long flags)
{
	return -EIO;
}