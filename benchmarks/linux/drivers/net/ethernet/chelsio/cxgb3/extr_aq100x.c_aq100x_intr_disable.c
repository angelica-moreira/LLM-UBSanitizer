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
struct cphy {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AQ_IMASK_GLOBAL ; 
 int /*<<< orphan*/  MDIO_MMD_VEND1 ; 
 int t3_mdio_write (struct cphy*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int aq100x_intr_disable(struct cphy *phy)
{
	return t3_mdio_write(phy, MDIO_MMD_VEND1, AQ_IMASK_GLOBAL, 0);
}