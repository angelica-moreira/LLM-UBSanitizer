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
struct nx_host_sds_ring {int /*<<< orphan*/  crb_intr_mask; struct netxen_adapter* adapter; } ;
struct netxen_adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  NXWRIO (struct netxen_adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void netxen_nic_disable_int(struct nx_host_sds_ring *sds_ring)
{
	struct netxen_adapter *adapter = sds_ring->adapter;

	NXWRIO(adapter, sds_ring->crb_intr_mask, 0);
}