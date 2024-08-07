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
typedef  scalar_t__ u8 ;
struct clk_hw {int dummy; } ;
struct alchemy_fgcs_clk {int /*<<< orphan*/  reglock; scalar_t__ isen; scalar_t__ parent; } ;

/* Variables and functions */
 int /*<<< orphan*/  __alchemy_clk_fgv2_en (struct alchemy_fgcs_clk*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ ,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ ,unsigned long) ; 
 struct alchemy_fgcs_clk* to_fgcs_clk (struct clk_hw*) ; 

__attribute__((used)) static int alchemy_clk_fgv2_setp(struct clk_hw *hw, u8 index)
{
	struct alchemy_fgcs_clk *c = to_fgcs_clk(hw);
	unsigned long flags;

	spin_lock_irqsave(c->reglock, flags);
	c->parent = index + 1;	/* value to write to register */
	if (c->isen)
		__alchemy_clk_fgv2_en(c);
	spin_unlock_irqrestore(c->reglock, flags);

	return 0;
}