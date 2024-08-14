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

/* Variables and functions */
 int /*<<< orphan*/  RDT_RESOURCE_L2 ; 
 int /*<<< orphan*/  RDT_RESOURCE_L2CODE ; 
 int /*<<< orphan*/  RDT_RESOURCE_L2DATA ; 
 int /*<<< orphan*/  rdt_get_cdp_config (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rdt_get_cdp_l2_config(void)
{
	rdt_get_cdp_config(RDT_RESOURCE_L2, RDT_RESOURCE_L2DATA);
	rdt_get_cdp_config(RDT_RESOURCE_L2, RDT_RESOURCE_L2CODE);
}