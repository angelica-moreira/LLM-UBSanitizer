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

/* Variables and functions */
 int TS72XX_MODEL_MASK ; 
 int /*<<< orphan*/  TS72XX_MODEL_VIRT_BASE ; 
 int __raw_readb (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int ts72xx_model(void)
{
	return __raw_readb(TS72XX_MODEL_VIRT_BASE) & TS72XX_MODEL_MASK;
}