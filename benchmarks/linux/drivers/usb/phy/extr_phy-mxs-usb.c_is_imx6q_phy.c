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
struct mxs_phy {int /*<<< orphan*/ * data; } ;

/* Variables and functions */
 int /*<<< orphan*/  imx6q_phy_data ; 

__attribute__((used)) static inline bool is_imx6q_phy(struct mxs_phy *mxs_phy)
{
	return mxs_phy->data == &imx6q_phy_data;
}