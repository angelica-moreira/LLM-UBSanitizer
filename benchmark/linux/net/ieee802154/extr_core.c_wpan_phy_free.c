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
struct wpan_phy {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  put_device (int /*<<< orphan*/ *) ; 

void wpan_phy_free(struct wpan_phy *phy)
{
	put_device(&phy->dev);
}