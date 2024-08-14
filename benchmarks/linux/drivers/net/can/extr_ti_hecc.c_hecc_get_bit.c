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
struct ti_hecc_priv {int dummy; } ;

/* Variables and functions */
 int hecc_read (struct ti_hecc_priv*,int) ; 

__attribute__((used)) static inline u32 hecc_get_bit(struct ti_hecc_priv *priv, int reg, u32 bit_mask)
{
	return (hecc_read(priv, reg) & bit_mask) ? 1 : 0;
}