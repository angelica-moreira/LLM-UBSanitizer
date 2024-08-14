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
 int /*<<< orphan*/  RDT_RESOURCE_L3 ; 
 int /*<<< orphan*/  RDT_RESOURCE_L3CODE ; 
 int /*<<< orphan*/  RDT_RESOURCE_L3DATA ; 
 int /*<<< orphan*/  cdp_disable (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void cdpl3_disable(void)
{
	cdp_disable(RDT_RESOURCE_L3, RDT_RESOURCE_L3DATA, RDT_RESOURCE_L3CODE);
}