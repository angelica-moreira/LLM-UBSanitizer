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
struct c_can_priv {int (* read_reg32 ) (struct c_can_priv const*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  C_CAN_FUNCTION_REG ; 
 int stub1 (struct c_can_priv const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void c_can_hw_raminit_wait(const struct c_can_priv *priv, u32 mask)
{
	while (priv->read_reg32(priv, C_CAN_FUNCTION_REG) & mask)
		udelay(1);
}