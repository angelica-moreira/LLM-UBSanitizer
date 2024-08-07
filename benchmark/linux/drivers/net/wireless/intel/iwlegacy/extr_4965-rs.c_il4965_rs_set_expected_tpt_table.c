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
struct il_scale_tbl_info {int /*<<< orphan*/ * expected_tpt; scalar_t__ is_SGI; int /*<<< orphan*/  is_ht40; int /*<<< orphan*/  lq_type; } ;
struct il_lq_sta {scalar_t__ is_agg; scalar_t__ is_dup; } ;
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 int RATE_COUNT ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 void* expected_tpt_legacy ; 
 int /*<<< orphan*/ ** expected_tpt_mimo2_20MHz ; 
 int /*<<< orphan*/ ** expected_tpt_mimo2_40MHz ; 
 int /*<<< orphan*/ ** expected_tpt_siso20MHz ; 
 int /*<<< orphan*/ ** expected_tpt_siso40MHz ; 
 int /*<<< orphan*/  is_Ht (int /*<<< orphan*/ ) ; 
 scalar_t__ is_legacy (int /*<<< orphan*/ ) ; 
 scalar_t__ is_mimo2 (int /*<<< orphan*/ ) ; 
 scalar_t__ is_siso (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
il4965_rs_set_expected_tpt_table(struct il_lq_sta *lq_sta,
				 struct il_scale_tbl_info *tbl)
{
	/* Used to choose among HT tables */
	s32(*ht_tbl_pointer)[RATE_COUNT];

	/* Check for invalid LQ type */
	if (WARN_ON_ONCE(!is_legacy(tbl->lq_type) && !is_Ht(tbl->lq_type))) {
		tbl->expected_tpt = expected_tpt_legacy;
		return;
	}

	/* Legacy rates have only one table */
	if (is_legacy(tbl->lq_type)) {
		tbl->expected_tpt = expected_tpt_legacy;
		return;
	}

	/* Choose among many HT tables depending on number of streams
	 * (SISO/MIMO2), channel width (20/40), SGI, and aggregation
	 * status */
	if (is_siso(tbl->lq_type) && (!tbl->is_ht40 || lq_sta->is_dup))
		ht_tbl_pointer = expected_tpt_siso20MHz;
	else if (is_siso(tbl->lq_type))
		ht_tbl_pointer = expected_tpt_siso40MHz;
	else if (is_mimo2(tbl->lq_type) && (!tbl->is_ht40 || lq_sta->is_dup))
		ht_tbl_pointer = expected_tpt_mimo2_20MHz;
	else			/* if (is_mimo2(tbl->lq_type)) <-- must be true */
		ht_tbl_pointer = expected_tpt_mimo2_40MHz;

	if (!tbl->is_SGI && !lq_sta->is_agg)	/* Normal */
		tbl->expected_tpt = ht_tbl_pointer[0];
	else if (tbl->is_SGI && !lq_sta->is_agg)	/* SGI */
		tbl->expected_tpt = ht_tbl_pointer[1];
	else if (!tbl->is_SGI && lq_sta->is_agg)	/* AGG */
		tbl->expected_tpt = ht_tbl_pointer[2];
	else			/* AGG+SGI */
		tbl->expected_tpt = ht_tbl_pointer[3];
}