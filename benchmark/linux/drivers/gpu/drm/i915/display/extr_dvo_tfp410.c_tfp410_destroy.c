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
struct tfp410_priv {int dummy; } ;
struct intel_dvo_device {struct tfp410_priv* dev_priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct tfp410_priv*) ; 

__attribute__((used)) static void tfp410_destroy(struct intel_dvo_device *dvo)
{
	struct tfp410_priv *tfp = dvo->dev_priv;

	if (tfp) {
		kfree(tfp);
		dvo->dev_priv = NULL;
	}
}