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
struct intel_dp {int* common_rates; int num_common_rates; } ;

/* Variables and functions */

__attribute__((used)) static int intel_dp_max_common_rate(struct intel_dp *intel_dp)
{
	return intel_dp->common_rates[intel_dp->num_common_rates - 1];
}