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
struct page_stat {int dummy; } ;

/* Variables and functions */
 struct page_stat* __page_stat__findnew_page (struct page_stat*,int) ; 

__attribute__((used)) static struct page_stat *page_stat__find_page(struct page_stat *pstat)
{
	return __page_stat__findnew_page(pstat, false);
}