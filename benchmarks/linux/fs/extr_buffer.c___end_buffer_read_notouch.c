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
struct buffer_head {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  clear_buffer_uptodate (struct buffer_head*) ; 
 int /*<<< orphan*/  set_buffer_uptodate (struct buffer_head*) ; 
 int /*<<< orphan*/  unlock_buffer (struct buffer_head*) ; 

__attribute__((used)) static void __end_buffer_read_notouch(struct buffer_head *bh, int uptodate)
{
	if (uptodate) {
		set_buffer_uptodate(bh);
	} else {
		/* This happens, due to failed read-ahead attempts. */
		clear_buffer_uptodate(bh);
	}
	unlock_buffer(bh);
}