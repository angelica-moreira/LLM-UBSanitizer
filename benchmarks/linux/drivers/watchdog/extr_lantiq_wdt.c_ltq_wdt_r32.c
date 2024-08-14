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
typedef  scalar_t__ u32 ;
struct ltq_wdt_priv {scalar_t__ membase; } ;

/* Variables and functions */
 scalar_t__ __raw_readl (scalar_t__) ; 

__attribute__((used)) static u32 ltq_wdt_r32(struct ltq_wdt_priv *priv, u32 offset)
{
	return __raw_readl(priv->membase + offset);
}