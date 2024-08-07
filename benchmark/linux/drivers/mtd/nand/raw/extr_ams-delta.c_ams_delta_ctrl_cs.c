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
struct ams_delta_nand {int /*<<< orphan*/  gpiod_nce; } ;

/* Variables and functions */
 int /*<<< orphan*/  gpiod_set_value (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void ams_delta_ctrl_cs(struct ams_delta_nand *priv, bool assert)
{
	gpiod_set_value(priv->gpiod_nce, assert ? 0 : 1);
}