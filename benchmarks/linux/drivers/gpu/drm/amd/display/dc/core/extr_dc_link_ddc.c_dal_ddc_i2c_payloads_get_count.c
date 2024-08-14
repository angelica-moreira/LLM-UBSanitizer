#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_2__ {int /*<<< orphan*/  count; } ;
struct i2c_payloads {TYPE_1__ payloads; } ;

/* Variables and functions */

__attribute__((used)) static uint32_t dal_ddc_i2c_payloads_get_count(struct i2c_payloads *p)
{
	return p->payloads.count;
}