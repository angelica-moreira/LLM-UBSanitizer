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
typedef  scalar_t__ u32 ;
struct clk_peripheral {scalar_t__ id; int /*<<< orphan*/  regmap; } ;
struct clk_hw {int dummy; } ;

/* Variables and functions */
 int AT91_PMC_PCSR ; 
 int AT91_PMC_PCSR1 ; 
 scalar_t__ PERIPHERAL_ID_MAX ; 
 scalar_t__ PERIPHERAL_ID_MIN ; 
 unsigned int PERIPHERAL_MASK (scalar_t__) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int,unsigned int*) ; 
 struct clk_peripheral* to_clk_peripheral (struct clk_hw*) ; 

__attribute__((used)) static int clk_peripheral_is_enabled(struct clk_hw *hw)
{
	struct clk_peripheral *periph = to_clk_peripheral(hw);
	int offset = AT91_PMC_PCSR;
	unsigned int status;
	u32 id = periph->id;

	if (id < PERIPHERAL_ID_MIN)
		return 1;
	if (id > PERIPHERAL_ID_MAX)
		offset = AT91_PMC_PCSR1;
	regmap_read(periph->regmap, offset, &status);

	return status & PERIPHERAL_MASK(id) ? 1 : 0;
}