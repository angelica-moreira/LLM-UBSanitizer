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
typedef  int u8 ;
struct inno_hdmi_phy {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int,int,int) ; 

__attribute__((used)) static inline void inno_update_bits(struct inno_hdmi_phy *inno, u8 reg,
				    u8 mask, u8 val)
{
	regmap_update_bits(inno->regmap, reg * 4, mask, val);
}