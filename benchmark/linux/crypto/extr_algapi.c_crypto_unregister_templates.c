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
struct crypto_template {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  crypto_unregister_template (struct crypto_template*) ; 

void crypto_unregister_templates(struct crypto_template *tmpls, int count)
{
	int i;

	for (i = count - 1; i >= 0; --i)
		crypto_unregister_template(&tmpls[i]);
}