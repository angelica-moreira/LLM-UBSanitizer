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
struct brcms_bss_cfg {struct brcms_bss_cfg* current_bss; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct brcms_bss_cfg*) ; 

__attribute__((used)) static void brcms_c_bsscfg_mfree(struct brcms_bss_cfg *cfg)
{
	if (cfg == NULL)
		return;

	kfree(cfg->current_bss);
	kfree(cfg);
}