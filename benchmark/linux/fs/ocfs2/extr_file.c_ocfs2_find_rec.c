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
typedef  scalar_t__ u32 ;
struct ocfs2_extent_rec {int /*<<< orphan*/  e_cpos; } ;
struct ocfs2_extent_list {struct ocfs2_extent_rec* l_recs; int /*<<< orphan*/  l_next_free_rec; } ;

/* Variables and functions */
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 scalar_t__ le32_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ocfs2_find_rec(struct ocfs2_extent_list *el, u32 pos)
{
	int i;
	struct ocfs2_extent_rec *rec = NULL;

	for (i = le16_to_cpu(el->l_next_free_rec) - 1; i >= 0; i--) {

		rec = &el->l_recs[i];

		if (le32_to_cpu(rec->e_cpos) < pos)
			break;
	}

	return i;
}