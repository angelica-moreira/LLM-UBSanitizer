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
struct mii_phy {int /*<<< orphan*/  dev; int /*<<< orphan*/  (* mdio_write ) (int /*<<< orphan*/ ,int,int,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int,int,int) ; 

__attribute__((used)) static inline void __sungem_phy_write(struct mii_phy* phy, int id, int reg, int val)
{
	phy->mdio_write(phy->dev, id, reg, val);
}