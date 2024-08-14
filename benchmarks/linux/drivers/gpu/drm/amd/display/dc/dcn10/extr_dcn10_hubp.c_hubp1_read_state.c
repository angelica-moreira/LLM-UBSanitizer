#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct hubp {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  pte_row_height_linear; int /*<<< orphan*/  swath_height; int /*<<< orphan*/  mpte_group_size; int /*<<< orphan*/  dpte_group_size; int /*<<< orphan*/  min_meta_chunk_size; int /*<<< orphan*/  meta_chunk_size; int /*<<< orphan*/  min_chunk_size; int /*<<< orphan*/  chunk_size; } ;
struct TYPE_3__ {int /*<<< orphan*/  pte_row_height_linear; int /*<<< orphan*/  swath_height; int /*<<< orphan*/  mpte_group_size; int /*<<< orphan*/  dpte_group_size; int /*<<< orphan*/  min_meta_chunk_size; int /*<<< orphan*/  meta_chunk_size; int /*<<< orphan*/  min_chunk_size; int /*<<< orphan*/  chunk_size; } ;
struct _vcs_dpi_display_rq_regs_st {TYPE_2__ rq_regs_c; TYPE_1__ rq_regs_l; } ;
struct dcn_hubp_state {struct _vcs_dpi_display_rq_regs_st rq_regs; } ;
struct dcn10_hubp {struct dcn_hubp_state state; } ;

/* Variables and functions */
 int /*<<< orphan*/  CHUNK_SIZE ; 
 int /*<<< orphan*/  CHUNK_SIZE_C ; 
 int /*<<< orphan*/  DCHUBP_REQ_SIZE_CONFIG ; 
 int /*<<< orphan*/  DCHUBP_REQ_SIZE_CONFIG_C ; 
 int /*<<< orphan*/  DPTE_GROUP_SIZE ; 
 int /*<<< orphan*/  DPTE_GROUP_SIZE_C ; 
 int /*<<< orphan*/  META_CHUNK_SIZE ; 
 int /*<<< orphan*/  META_CHUNK_SIZE_C ; 
 int /*<<< orphan*/  MIN_CHUNK_SIZE ; 
 int /*<<< orphan*/  MIN_CHUNK_SIZE_C ; 
 int /*<<< orphan*/  MIN_META_CHUNK_SIZE ; 
 int /*<<< orphan*/  MIN_META_CHUNK_SIZE_C ; 
 int /*<<< orphan*/  MPTE_GROUP_SIZE ; 
 int /*<<< orphan*/  MPTE_GROUP_SIZE_C ; 
 int /*<<< orphan*/  PTE_ROW_HEIGHT_LINEAR ; 
 int /*<<< orphan*/  PTE_ROW_HEIGHT_LINEAR_C ; 
 int /*<<< orphan*/  REG_GET_8 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SWATH_HEIGHT ; 
 int /*<<< orphan*/  SWATH_HEIGHT_C ; 
 struct dcn10_hubp* TO_DCN10_HUBP (struct hubp*) ; 
 int /*<<< orphan*/  hubp1_read_state_common (struct hubp*) ; 

void hubp1_read_state(struct hubp *hubp)
{
	struct dcn10_hubp *hubp1 = TO_DCN10_HUBP(hubp);
	struct dcn_hubp_state *s = &hubp1->state;
	struct _vcs_dpi_display_rq_regs_st *rq_regs = &s->rq_regs;

	hubp1_read_state_common(hubp);

	REG_GET_8(DCHUBP_REQ_SIZE_CONFIG,
		CHUNK_SIZE, &rq_regs->rq_regs_l.chunk_size,
		MIN_CHUNK_SIZE, &rq_regs->rq_regs_l.min_chunk_size,
		META_CHUNK_SIZE, &rq_regs->rq_regs_l.meta_chunk_size,
		MIN_META_CHUNK_SIZE, &rq_regs->rq_regs_l.min_meta_chunk_size,
		DPTE_GROUP_SIZE, &rq_regs->rq_regs_l.dpte_group_size,
		MPTE_GROUP_SIZE, &rq_regs->rq_regs_l.mpte_group_size,
		SWATH_HEIGHT, &rq_regs->rq_regs_l.swath_height,
		PTE_ROW_HEIGHT_LINEAR, &rq_regs->rq_regs_l.pte_row_height_linear);

	REG_GET_8(DCHUBP_REQ_SIZE_CONFIG_C,
		CHUNK_SIZE_C, &rq_regs->rq_regs_c.chunk_size,
		MIN_CHUNK_SIZE_C, &rq_regs->rq_regs_c.min_chunk_size,
		META_CHUNK_SIZE_C, &rq_regs->rq_regs_c.meta_chunk_size,
		MIN_META_CHUNK_SIZE_C, &rq_regs->rq_regs_c.min_meta_chunk_size,
		DPTE_GROUP_SIZE_C, &rq_regs->rq_regs_c.dpte_group_size,
		MPTE_GROUP_SIZE_C, &rq_regs->rq_regs_c.mpte_group_size,
		SWATH_HEIGHT_C, &rq_regs->rq_regs_c.swath_height,
		PTE_ROW_HEIGHT_LINEAR_C, &rq_regs->rq_regs_c.pte_row_height_linear);

}