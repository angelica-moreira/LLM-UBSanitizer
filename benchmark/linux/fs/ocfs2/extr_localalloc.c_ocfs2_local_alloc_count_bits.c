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
typedef  int /*<<< orphan*/  u32 ;
struct ocfs2_local_alloc {int /*<<< orphan*/  la_size; int /*<<< orphan*/  la_bitmap; } ;
struct ocfs2_dinode {int dummy; } ;

/* Variables and functions */
 struct ocfs2_local_alloc* OCFS2_LOCAL_ALLOC (struct ocfs2_dinode*) ; 
 int /*<<< orphan*/  le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memweight (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_ocfs2_local_alloc_count_bits (int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32 ocfs2_local_alloc_count_bits(struct ocfs2_dinode *alloc)
{
	u32 count;
	struct ocfs2_local_alloc *la = OCFS2_LOCAL_ALLOC(alloc);

	count = memweight(la->la_bitmap, le16_to_cpu(la->la_size));

	trace_ocfs2_local_alloc_count_bits(count);
	return count;
}