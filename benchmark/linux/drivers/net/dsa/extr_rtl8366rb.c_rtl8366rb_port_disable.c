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
struct realtek_smi {int /*<<< orphan*/  map; int /*<<< orphan*/  dev; } ;
struct dsa_switch {struct realtek_smi* priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  BIT (int) ; 
 int /*<<< orphan*/  RTL8366RB_PECR ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  rb8366rb_set_port_led (struct realtek_smi*,int,int) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
rtl8366rb_port_disable(struct dsa_switch *ds, int port)
{
	struct realtek_smi *smi = ds->priv;
	int ret;

	dev_dbg(smi->dev, "disable port %d\n", port);
	ret = regmap_update_bits(smi->map, RTL8366RB_PECR, BIT(port),
				 BIT(port));
	if (ret)
		return;

	rb8366rb_set_port_led(smi, port, false);
}