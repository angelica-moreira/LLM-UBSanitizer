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
struct dce_i2c_sw {struct dc_context* ctx; } ;
struct dc_context {int dummy; } ;

/* Variables and functions */

void dce_i2c_sw_construct(
	struct dce_i2c_sw *dce_i2c_sw,
	struct dc_context *ctx)
{
	dce_i2c_sw->ctx = ctx;
}