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
 int __set_page_dirty_nobuffers (struct page*) ; 

__attribute__((used)) static int btrfs_set_page_dirty(struct page *page)
{
	return __set_page_dirty_nobuffers(page);
}