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
struct zd_rf {int patch_cck_gain; } ;

/* Variables and functions */

__attribute__((used)) static inline int zd_rf_should_patch_cck_gain(struct zd_rf *rf)
{
	return rf->patch_cck_gain;
}