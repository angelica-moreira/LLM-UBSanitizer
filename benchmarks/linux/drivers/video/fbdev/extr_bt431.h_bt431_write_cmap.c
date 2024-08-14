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
typedef  int /*<<< orphan*/  u16 ;
struct bt431_regs {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bt431_select_reg (struct bt431_regs*,int) ; 
 int /*<<< orphan*/  bt431_write_cmap_inc (struct bt431_regs*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void bt431_write_cmap(struct bt431_regs *regs, int cr, u16 value)
{
	bt431_select_reg(regs, cr);
	bt431_write_cmap_inc(regs, value);
}