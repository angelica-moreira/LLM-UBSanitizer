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
typedef  int /*<<< orphan*/  u8 ;
struct qed_hwfn {TYPE_3__* vf_iov_info; } ;
struct TYPE_4__ {int /*<<< orphan*/  port_mac; } ;
struct TYPE_5__ {TYPE_1__ pfdev_info; } ;
struct TYPE_6__ {TYPE_2__ acquire_resp; } ;

/* Variables and functions */
 int /*<<< orphan*/  ETH_ALEN ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void qed_vf_get_port_mac(struct qed_hwfn *p_hwfn, u8 *port_mac)
{
	memcpy(port_mac,
	       p_hwfn->vf_iov_info->acquire_resp.pfdev_info.port_mac, ETH_ALEN);
}