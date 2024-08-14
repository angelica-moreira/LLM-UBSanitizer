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
typedef  int u32 ;
typedef  int u16 ;
struct i40e_vf {int num_tc; size_t lan_vsi_idx; int lan_vsi_id; TYPE_1__* ch; scalar_t__ adq_enabled; struct i40e_pf* pf; } ;
struct i40e_hw {int dummy; } ;
struct i40e_pf {TYPE_2__** vsi; struct i40e_hw hw; } ;
struct TYPE_4__ {int alloc_queue_pairs; } ;
struct TYPE_3__ {int num_qps; int vsi_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  I40E_VSILAN_QTABLE (int,int) ; 
 int i40e_vc_get_pf_queue_id (struct i40e_vf*,int,int) ; 
 int /*<<< orphan*/  i40e_write_rx_ctl (struct i40e_hw*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void i40e_map_pf_queues_to_vsi(struct i40e_vf *vf)
{
	struct i40e_pf *pf = vf->pf;
	struct i40e_hw *hw = &pf->hw;
	u32 reg, num_tc = 1; /* VF has at least one traffic class */
	u16 vsi_id, qps;
	int i, j;

	if (vf->adq_enabled)
		num_tc = vf->num_tc;

	for (i = 0; i < num_tc; i++) {
		if (vf->adq_enabled) {
			qps = vf->ch[i].num_qps;
			vsi_id =  vf->ch[i].vsi_id;
		} else {
			qps = pf->vsi[vf->lan_vsi_idx]->alloc_queue_pairs;
			vsi_id = vf->lan_vsi_id;
		}

		for (j = 0; j < 7; j++) {
			if (j * 2 >= qps) {
				/* end of list */
				reg = 0x07FF07FF;
			} else {
				u16 qid = i40e_vc_get_pf_queue_id(vf,
								  vsi_id,
								  j * 2);
				reg = qid;
				qid = i40e_vc_get_pf_queue_id(vf, vsi_id,
							      (j * 2) + 1);
				reg |= qid << 16;
			}
			i40e_write_rx_ctl(hw,
					  I40E_VSILAN_QTABLE(j, vsi_id),
					  reg);
		}
	}
}