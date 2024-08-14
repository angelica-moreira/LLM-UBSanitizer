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
struct qlcnic_dcb {TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* aen_handler ) (struct qlcnic_dcb*,void*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct qlcnic_dcb*,void*) ; 

__attribute__((used)) static inline void qlcnic_dcb_aen_handler(struct qlcnic_dcb *dcb, void *msg)
{
	if (dcb && dcb->ops->aen_handler)
		dcb->ops->aen_handler(dcb, msg);
}