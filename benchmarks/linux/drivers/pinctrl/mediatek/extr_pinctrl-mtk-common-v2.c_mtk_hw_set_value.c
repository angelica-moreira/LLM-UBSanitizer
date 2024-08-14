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
struct mtk_pinctrl {int dummy; } ;
struct mtk_pin_field {int mask; int bitpos; int /*<<< orphan*/  offset; int /*<<< orphan*/  index; int /*<<< orphan*/  next; } ;
struct mtk_pin_desc {int dummy; } ;

/* Variables and functions */
 int mtk_hw_pin_field_get (struct mtk_pinctrl*,struct mtk_pin_desc const*,int,struct mtk_pin_field*) ; 
 int /*<<< orphan*/  mtk_hw_write_cross_field (struct mtk_pinctrl*,struct mtk_pin_field*,int) ; 
 int /*<<< orphan*/  mtk_rmw (struct mtk_pinctrl*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 

int mtk_hw_set_value(struct mtk_pinctrl *hw, const struct mtk_pin_desc *desc,
		     int field, int value)
{
	struct mtk_pin_field pf;
	int err;

	err = mtk_hw_pin_field_get(hw, desc, field, &pf);
	if (err)
		return err;

	if (!pf.next)
		mtk_rmw(hw, pf.index, pf.offset, pf.mask << pf.bitpos,
			(value & pf.mask) << pf.bitpos);
	else
		mtk_hw_write_cross_field(hw, &pf, value);

	return 0;
}