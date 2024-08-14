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
struct dm_buffer {scalar_t__ hold_count; int /*<<< orphan*/  state; } ;
typedef  int gfp_t ;

/* Variables and functions */
 int /*<<< orphan*/  B_DIRTY ; 
 int /*<<< orphan*/  B_READING ; 
 int /*<<< orphan*/  B_WRITING ; 
 int __GFP_FS ; 
 int /*<<< orphan*/  __free_buffer_wake (struct dm_buffer*) ; 
 int /*<<< orphan*/  __make_buffer_clean (struct dm_buffer*) ; 
 int /*<<< orphan*/  __unlink_buffer (struct dm_buffer*) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool __try_evict_buffer(struct dm_buffer *b, gfp_t gfp)
{
	if (!(gfp & __GFP_FS)) {
		if (test_bit(B_READING, &b->state) ||
		    test_bit(B_WRITING, &b->state) ||
		    test_bit(B_DIRTY, &b->state))
			return false;
	}

	if (b->hold_count)
		return false;

	__make_buffer_clean(b);
	__unlink_buffer(b);
	__free_buffer_wake(b);

	return true;
}