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
struct vnic_wq {int dummy; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  WQ_ENET_OFFLOAD_MODE_CSUM ; 
 int /*<<< orphan*/  enic_queue_wq_desc_ex (struct vnic_wq*,void*,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned int,int /*<<< orphan*/ ,int,int,int,int) ; 

__attribute__((used)) static inline void enic_queue_wq_desc(struct vnic_wq *wq, void *os_buf,
	dma_addr_t dma_addr, unsigned int len, int vlan_tag_insert,
	unsigned int vlan_tag, int eop, int loopback)
{
	enic_queue_wq_desc_ex(wq, os_buf, dma_addr, len,
		0, 0, vlan_tag_insert, vlan_tag,
		WQ_ENET_OFFLOAD_MODE_CSUM,
		eop, 1 /* SOP */, eop, loopback);
}