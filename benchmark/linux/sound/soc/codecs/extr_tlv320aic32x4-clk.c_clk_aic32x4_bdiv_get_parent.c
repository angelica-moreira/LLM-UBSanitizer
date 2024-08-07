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
typedef  unsigned int u8 ;
struct clk_hw {int dummy; } ;
struct clk_aic32x4 {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 unsigned int AIC32X4_BDIVCLK_MASK ; 
 int /*<<< orphan*/  AIC32X4_IFACE3 ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 struct clk_aic32x4* to_clk_aic32x4 (struct clk_hw*) ; 

__attribute__((used)) static u8 clk_aic32x4_bdiv_get_parent(struct clk_hw *hw)
{
	struct clk_aic32x4 *mux = to_clk_aic32x4(hw);
	unsigned int val;

	regmap_read(mux->regmap, AIC32X4_IFACE3, &val);

	return val & AIC32X4_BDIVCLK_MASK;
}