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
struct ext4_buddy {scalar_t__ bd_buddy_page; scalar_t__ bd_bitmap_page; } ;

/* Variables and functions */
 int /*<<< orphan*/  put_page (scalar_t__) ; 
 int /*<<< orphan*/  unlock_page (scalar_t__) ; 

__attribute__((used)) static void ext4_mb_put_buddy_page_lock(struct ext4_buddy *e4b)
{
	if (e4b->bd_bitmap_page) {
		unlock_page(e4b->bd_bitmap_page);
		put_page(e4b->bd_bitmap_page);
	}
	if (e4b->bd_buddy_page) {
		unlock_page(e4b->bd_buddy_page);
		put_page(e4b->bd_buddy_page);
	}
}