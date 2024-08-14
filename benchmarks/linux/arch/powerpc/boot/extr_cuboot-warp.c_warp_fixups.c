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
struct TYPE_2__ {int /*<<< orphan*/  bi_enetaddr; } ;

/* Variables and functions */
 TYPE_1__ bd ; 
 int /*<<< orphan*/  dt_fixup_mac_address_by_alias (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ibm440ep_fixup_clocks (int,int,int) ; 
 int /*<<< orphan*/  ibm4xx_fixup_ebc_ranges (char*) ; 
 int /*<<< orphan*/  ibm4xx_sdram_fixup_memsize () ; 

__attribute__((used)) static void warp_fixups(void)
{
	ibm440ep_fixup_clocks(66000000, 11059200, 50000000);
	ibm4xx_sdram_fixup_memsize();
	ibm4xx_fixup_ebc_ranges("/plb/opb/ebc");
	dt_fixup_mac_address_by_alias("ethernet0", bd.bi_enetaddr);
}