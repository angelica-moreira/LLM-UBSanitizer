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
struct extent_buffer {int /*<<< orphan*/  bflags; } ;

/* Variables and functions */
 int /*<<< orphan*/  EXTENT_BUFFER_UPTODATE ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int extent_buffer_uptodate(struct extent_buffer *eb)
{
	return test_bit(EXTENT_BUFFER_UPTODATE, &eb->bflags);
}