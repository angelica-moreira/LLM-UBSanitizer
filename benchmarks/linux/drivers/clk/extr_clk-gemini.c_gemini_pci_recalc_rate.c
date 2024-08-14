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
typedef  int u32 ;
struct clk_hw {int dummy; } ;
struct clk_gemini_pci {int /*<<< orphan*/  map; } ;

/* Variables and functions */
 int /*<<< orphan*/  GEMINI_GLOBAL_MISC_CONTROL ; 
 int PCI_CLK_66MHZ ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 struct clk_gemini_pci* to_pciclk (struct clk_hw*) ; 

__attribute__((used)) static unsigned long gemini_pci_recalc_rate(struct clk_hw *hw,
					    unsigned long parent_rate)
{
	struct clk_gemini_pci *pciclk = to_pciclk(hw);
	u32 val;

	regmap_read(pciclk->map, GEMINI_GLOBAL_MISC_CONTROL, &val);
	if (val & PCI_CLK_66MHZ)
		return 66000000;
	return 33000000;
}