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
struct sun4i_i2s_clk_div {int div; int val; } ;
struct sun4i_i2s {TYPE_1__* variant; } ;
struct TYPE_2__ {int num_mclk_dividers; struct sun4i_i2s_clk_div* mclk_dividers; } ;

/* Variables and functions */
 int EINVAL ; 

__attribute__((used)) static int sun4i_i2s_get_mclk_div(struct sun4i_i2s *i2s,
				  unsigned long parent_rate,
				  unsigned long mclk_rate)
{
	const struct sun4i_i2s_clk_div *dividers = i2s->variant->mclk_dividers;
	int div = parent_rate / mclk_rate;
	int i;

	for (i = 0; i < i2s->variant->num_mclk_dividers; i++) {
		const struct sun4i_i2s_clk_div *mdiv = &dividers[i];

		if (mdiv->div == div)
			return mdiv->val;
	}

	return -EINVAL;
}