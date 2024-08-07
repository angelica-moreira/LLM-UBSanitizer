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
struct hix5hd2_i2c_priv {int /*<<< orphan*/  clk; } ;

/* Variables and functions */
 int /*<<< orphan*/  clk_disable_unprepare (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clk_prepare_enable (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hix5hd2_i2c_init (struct hix5hd2_i2c_priv*) ; 
 int /*<<< orphan*/  msleep (int) ; 

__attribute__((used)) static void hix5hd2_i2c_reset(struct hix5hd2_i2c_priv *priv)
{
	clk_disable_unprepare(priv->clk);
	msleep(20);
	clk_prepare_enable(priv->clk);
	hix5hd2_i2c_init(priv);
}