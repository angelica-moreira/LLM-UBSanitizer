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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u16 ;
struct encx24j600_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  encx24j600_update_reg (struct encx24j600_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void encx24j600_set_bits(struct encx24j600_priv *priv, u8 reg, u16 mask)
{
	encx24j600_update_reg(priv, reg, mask, mask);
}