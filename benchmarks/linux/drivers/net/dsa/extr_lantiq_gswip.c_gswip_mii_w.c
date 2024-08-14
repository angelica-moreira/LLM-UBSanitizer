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
struct gswip_priv {scalar_t__ mii; } ;

/* Variables and functions */
 int /*<<< orphan*/  __raw_writel (int,scalar_t__) ; 

__attribute__((used)) static void gswip_mii_w(struct gswip_priv *priv, u32 val, u32 offset)
{
	__raw_writel(val, priv->mii + (offset * 4));
}