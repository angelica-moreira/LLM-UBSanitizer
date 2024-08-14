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
typedef  int u32 ;
struct mmci_host {TYPE_1__* data; } ;
struct TYPE_2__ {int blksz; } ;

/* Variables and functions */
 int MCI_DPSM_ENABLE ; 

__attribute__((used)) static u32 qcom_get_dctrl_cfg(struct mmci_host *host)
{
	return MCI_DPSM_ENABLE | (host->data->blksz << 4);
}