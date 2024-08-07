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
struct nullb_page {int /*<<< orphan*/  bitmap; } ;

/* Variables and functions */
 int MAP_SZ ; 
 int find_first_bit (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static bool null_page_empty(struct nullb_page *page)
{
	int size = MAP_SZ - 2;

	return find_first_bit(page->bitmap, size) == size;
}