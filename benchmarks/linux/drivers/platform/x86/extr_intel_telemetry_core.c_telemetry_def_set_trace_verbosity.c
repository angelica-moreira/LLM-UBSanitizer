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
typedef  int /*<<< orphan*/  u32 ;
typedef  enum telemetry_unit { ____Placeholder_telemetry_unit } telemetry_unit ;

/* Variables and functions */

__attribute__((used)) static int telemetry_def_set_trace_verbosity(enum telemetry_unit telem_unit,
					     u32 verbosity)
{
	return 0;
}