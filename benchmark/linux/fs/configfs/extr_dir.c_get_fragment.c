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
struct configfs_fragment {int /*<<< orphan*/  frag_count; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 scalar_t__ likely (struct configfs_fragment*) ; 

struct configfs_fragment *get_fragment(struct configfs_fragment *frag)
{
	if (likely(frag))
		atomic_inc(&frag->frag_count);
	return frag;
}