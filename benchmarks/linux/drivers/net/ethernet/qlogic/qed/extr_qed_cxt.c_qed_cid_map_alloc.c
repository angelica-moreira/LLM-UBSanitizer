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
typedef  size_t u32 ;
struct qed_hwfn {struct qed_cxt_mngr* p_cxt_mngr; } ;
struct qed_cxt_mngr {struct qed_cid_acquired_map** acquired_vf; struct qed_cid_acquired_map* acquired; struct qed_conn_type_cfg* conn_cfg; } ;
struct qed_conn_type_cfg {scalar_t__ cids_per_vf; scalar_t__ cid_count; } ;
struct qed_cid_acquired_map {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 size_t MAX_CONN_TYPES ; 
 size_t MAX_NUM_VFS ; 
 scalar_t__ qed_cid_map_alloc_single (struct qed_hwfn*,size_t,size_t,scalar_t__,struct qed_cid_acquired_map*) ; 
 int /*<<< orphan*/  qed_cid_map_free (struct qed_hwfn*) ; 

__attribute__((used)) static int qed_cid_map_alloc(struct qed_hwfn *p_hwfn)
{
	struct qed_cxt_mngr *p_mngr = p_hwfn->p_cxt_mngr;
	u32 start_cid = 0, vf_start_cid = 0;
	u32 type, vf;

	for (type = 0; type < MAX_CONN_TYPES; type++) {
		struct qed_conn_type_cfg *p_cfg = &p_mngr->conn_cfg[type];
		struct qed_cid_acquired_map *p_map;

		/* Handle PF maps */
		p_map = &p_mngr->acquired[type];
		if (qed_cid_map_alloc_single(p_hwfn, type, start_cid,
					     p_cfg->cid_count, p_map))
			goto cid_map_fail;

		/* Handle VF maps */
		for (vf = 0; vf < MAX_NUM_VFS; vf++) {
			p_map = &p_mngr->acquired_vf[type][vf];
			if (qed_cid_map_alloc_single(p_hwfn, type,
						     vf_start_cid,
						     p_cfg->cids_per_vf, p_map))
				goto cid_map_fail;
		}

		start_cid += p_cfg->cid_count;
		vf_start_cid += p_cfg->cids_per_vf;
	}

	return 0;

cid_map_fail:
	qed_cid_map_free(p_hwfn);
	return -ENOMEM;
}