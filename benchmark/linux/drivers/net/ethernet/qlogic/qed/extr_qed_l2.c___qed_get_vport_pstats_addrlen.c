#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_4__ {int address; int len; } ;
struct TYPE_5__ {TYPE_1__ pstats; } ;
struct TYPE_6__ {TYPE_2__ stats_info; } ;
struct pfvf_acquire_resp_tlv {TYPE_3__ pfdev_info; } ;
struct qed_vf_iov {struct pfvf_acquire_resp_tlv acquire_resp; } ;
struct qed_hwfn {struct qed_vf_iov* vf_iov_info; int /*<<< orphan*/  cdev; } ;
struct eth_pstorm_per_queue_stat {int dummy; } ;

/* Variables and functions */
 int BAR0_MAP_REG_PSDM_RAM ; 
 scalar_t__ IS_PF (int /*<<< orphan*/ ) ; 
 int PSTORM_QUEUE_STAT_OFFSET (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void __qed_get_vport_pstats_addrlen(struct qed_hwfn *p_hwfn,
					   u32 *p_addr,
					   u32 *p_len, u16 statistics_bin)
{
	if (IS_PF(p_hwfn->cdev)) {
		*p_addr = BAR0_MAP_REG_PSDM_RAM +
		    PSTORM_QUEUE_STAT_OFFSET(statistics_bin);
		*p_len = sizeof(struct eth_pstorm_per_queue_stat);
	} else {
		struct qed_vf_iov *p_iov = p_hwfn->vf_iov_info;
		struct pfvf_acquire_resp_tlv *p_resp = &p_iov->acquire_resp;

		*p_addr = p_resp->pfdev_info.stats_info.pstats.address;
		*p_len = p_resp->pfdev_info.stats_info.pstats.len;
	}
}