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
struct metapage {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ClearPagePrivate (struct page*) ; 
 int /*<<< orphan*/  kunmap (struct page*) ; 
 int /*<<< orphan*/  set_page_private (struct page*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void remove_metapage(struct page *page, struct metapage *mp)
{
	set_page_private(page, 0);
	ClearPagePrivate(page);
	kunmap(page);
}