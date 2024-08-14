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
 int /*<<< orphan*/  SV_LEAK ; 
 int /*<<< orphan*/  klp_shadow_free_all (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  livepatch_fix1_dummy_leak_dtor ; 

__attribute__((used)) static void livepatch_shadow_fix1_exit(void)
{
	/* Cleanup any existing SV_LEAK shadow variables */
	klp_shadow_free_all(SV_LEAK, livepatch_fix1_dummy_leak_dtor);
}