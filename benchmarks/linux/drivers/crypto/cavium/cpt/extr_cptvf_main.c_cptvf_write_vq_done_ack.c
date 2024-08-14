#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  done_ack; } ;
union cptx_vqx_done_ack {int /*<<< orphan*/  u; TYPE_1__ s; } ;
typedef  int /*<<< orphan*/  u32 ;
struct cpt_vf {int /*<<< orphan*/  reg_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPTX_VQX_DONE_ACK (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpt_read_csr64 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpt_write_csr64 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void cptvf_write_vq_done_ack(struct cpt_vf *cptvf,
					   u32 ackcnt)
{
	union cptx_vqx_done_ack vqx_dack_cnt;

	vqx_dack_cnt.u = cpt_read_csr64(cptvf->reg_base,
					CPTX_VQX_DONE_ACK(0, 0));
	vqx_dack_cnt.s.done_ack = ackcnt;
	cpt_write_csr64(cptvf->reg_base, CPTX_VQX_DONE_ACK(0, 0),
			vqx_dack_cnt.u);
}