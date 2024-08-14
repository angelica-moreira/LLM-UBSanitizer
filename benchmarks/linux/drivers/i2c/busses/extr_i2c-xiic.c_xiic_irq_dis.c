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
struct xiic_i2c {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  XIIC_IIER_OFFSET ; 
 int xiic_getreg32 (struct xiic_i2c*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xiic_setreg32 (struct xiic_i2c*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void xiic_irq_dis(struct xiic_i2c *i2c, u32 mask)
{
	u32 ier = xiic_getreg32(i2c, XIIC_IIER_OFFSET);
	xiic_setreg32(i2c, XIIC_IIER_OFFSET, ier & ~mask);
}