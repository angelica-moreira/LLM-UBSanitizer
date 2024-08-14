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
struct rtsx_pcr {TYPE_1__* ops; } ;
struct TYPE_2__ {int (* card_power_off ) (struct rtsx_pcr*,int) ;} ;

/* Variables and functions */
 int stub1 (struct rtsx_pcr*,int) ; 

int rtsx_pci_card_power_off(struct rtsx_pcr *pcr, int card)
{
	if (pcr->ops->card_power_off)
		return pcr->ops->card_power_off(pcr, card);

	return 0;
}