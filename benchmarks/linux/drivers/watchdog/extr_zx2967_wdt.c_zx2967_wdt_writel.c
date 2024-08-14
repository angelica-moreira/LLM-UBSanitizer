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
typedef  scalar_t__ u16 ;
struct zx2967_wdt {scalar_t__ reg_base; } ;

/* Variables and functions */
 int ZX2967_WDT_WRITEKEY ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

__attribute__((used)) static inline void zx2967_wdt_writel(struct zx2967_wdt *wdt, u16 reg, u32 val)
{
	writel_relaxed(val | ZX2967_WDT_WRITEKEY, wdt->reg_base + reg);
}