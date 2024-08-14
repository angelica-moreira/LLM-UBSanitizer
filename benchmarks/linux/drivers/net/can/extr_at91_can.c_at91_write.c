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
typedef  int /*<<< orphan*/  u32 ;
struct at91_priv {int reg_base; } ;
typedef  enum at91_reg { ____Placeholder_at91_reg } at91_reg ;

/* Variables and functions */
 int /*<<< orphan*/  writel_relaxed (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void at91_write(const struct at91_priv *priv, enum at91_reg reg,
		u32 value)
{
	writel_relaxed(value, priv->reg_base + reg);
}