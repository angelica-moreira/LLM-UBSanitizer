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
typedef  unsigned int u64 ;
struct i915_syncmap {int /*<<< orphan*/  height; } ;

/* Variables and functions */
 int /*<<< orphan*/  GEM_BUG_ON (int /*<<< orphan*/ ) ; 
 unsigned int MASK ; 

__attribute__((used)) static inline unsigned int
__sync_leaf_idx(const struct i915_syncmap *p, u64 id)
{
	GEM_BUG_ON(p->height);
	return id & MASK;
}