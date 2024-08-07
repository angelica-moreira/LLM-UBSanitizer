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
struct qib_pportdata {TYPE_1__* dd; } ;
struct TYPE_2__ {scalar_t__ (* f_get_ib_cfg ) (struct qib_pportdata*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 scalar_t__ IB_LINKINITCMD_SLEEP ; 
 int /*<<< orphan*/  QIB_IB_CFG_LINKDEFAULT ; 
 scalar_t__ stub1 (struct qib_pportdata*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int get_linkdowndefaultstate(struct qib_pportdata *ppd)
{
	return ppd->dd->f_get_ib_cfg(ppd, QIB_IB_CFG_LINKDEFAULT) ==
		IB_LINKINITCMD_SLEEP;
}