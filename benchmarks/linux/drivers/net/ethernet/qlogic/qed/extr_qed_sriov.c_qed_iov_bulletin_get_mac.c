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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_4__ {TYPE_1__* p_virt; } ;
struct qed_vf_info {TYPE_2__ bulletin; } ;
struct qed_hwfn {int dummy; } ;
struct TYPE_3__ {int valid_bitmap; int /*<<< orphan*/ * mac; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VFPF_BULLETIN_MAC_ADDR ; 
 struct qed_vf_info* qed_iov_get_vf_info (struct qed_hwfn*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static u8 *qed_iov_bulletin_get_mac(struct qed_hwfn *p_hwfn, u16 rel_vf_id)
{
	struct qed_vf_info *p_vf;

	p_vf = qed_iov_get_vf_info(p_hwfn, rel_vf_id, true);
	if (!p_vf || !p_vf->bulletin.p_virt)
		return NULL;

	if (!(p_vf->bulletin.p_virt->valid_bitmap &
	      BIT(VFPF_BULLETIN_MAC_ADDR)))
		return NULL;

	return p_vf->bulletin.p_virt->mac;
}