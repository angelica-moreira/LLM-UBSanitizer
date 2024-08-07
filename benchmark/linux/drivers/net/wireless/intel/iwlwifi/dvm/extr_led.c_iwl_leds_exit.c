#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  name; } ;
struct iwl_priv {TYPE_1__ led; int /*<<< orphan*/  led_registered; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  led_classdev_unregister (TYPE_1__*) ; 

void iwl_leds_exit(struct iwl_priv *priv)
{
	if (!priv->led_registered)
		return;

	led_classdev_unregister(&priv->led);
	kfree(priv->led.name);
}