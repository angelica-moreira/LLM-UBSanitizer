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
struct phy {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ENODEV ; 
 scalar_t__ IS_ERR (struct phy*) ; 
 int /*<<< orphan*/  PTR_ERR (struct phy*) ; 
 struct phy* devm_phy_get (struct device*,char const*) ; 

struct phy *devm_phy_optional_get(struct device *dev, const char *string)
{
	struct phy *phy = devm_phy_get(dev, string);

	if (IS_ERR(phy) && (PTR_ERR(phy) == -ENODEV))
		phy = NULL;

	return phy;
}