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
struct ocfs2_alloc_reservation {unsigned int r_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (unsigned int) ; 
 unsigned int OCFS2_RESV_TYPES ; 

void ocfs2_resv_set_type(struct ocfs2_alloc_reservation *resv,
			 unsigned int flags)
{
	BUG_ON(flags & ~OCFS2_RESV_TYPES);

	resv->r_flags |= flags;
}