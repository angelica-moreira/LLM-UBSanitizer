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
typedef  int /*<<< orphan*/  u32 ;
struct qlcnic_adapter {TYPE_2__* ahw; } ;
struct TYPE_4__ {TYPE_1__* hw_ops; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* get_cap_size ) (void*,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (void*,int) ; 

__attribute__((used)) static inline u32 qlcnic_get_cap_size(struct qlcnic_adapter *adapter,
				      void *tmpl_hdr, int index)
{
	return adapter->ahw->hw_ops->get_cap_size(tmpl_hdr, index);
}