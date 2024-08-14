#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct atmel_ebi_dev_config {int /*<<< orphan*/  smcconf; int /*<<< orphan*/  cs; } ;
struct atmel_ebi_dev {TYPE_2__* ebi; } ;
struct TYPE_3__ {int /*<<< orphan*/  regmap; } ;
struct TYPE_4__ {TYPE_1__ smc; } ;

/* Variables and functions */
 int /*<<< orphan*/  atmel_smc_cs_conf_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void at91sam9_ebi_get_config(struct atmel_ebi_dev *ebid,
				    struct atmel_ebi_dev_config *conf)
{
	atmel_smc_cs_conf_get(ebid->ebi->smc.regmap, conf->cs,
			      &conf->smcconf);
}