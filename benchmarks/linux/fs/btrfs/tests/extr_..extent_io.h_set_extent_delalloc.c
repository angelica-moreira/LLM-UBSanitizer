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
typedef  int /*<<< orphan*/  u64 ;
struct extent_state {int dummy; } ;
struct extent_io_tree {int dummy; } ;

/* Variables and functions */
 unsigned int EXTENT_DELALLOC ; 
 unsigned int EXTENT_UPTODATE ; 
 int /*<<< orphan*/  GFP_NOFS ; 
 int set_extent_bit (struct extent_io_tree*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ *,struct extent_state**,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int set_extent_delalloc(struct extent_io_tree *tree, u64 start,
				      u64 end, unsigned int extra_bits,
				      struct extent_state **cached_state)
{
	return set_extent_bit(tree, start, end,
			      EXTENT_DELALLOC | EXTENT_UPTODATE | extra_bits,
			      NULL, cached_state, GFP_NOFS);
}