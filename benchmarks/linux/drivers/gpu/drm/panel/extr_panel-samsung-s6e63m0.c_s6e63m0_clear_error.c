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
struct s6e63m0 {int error; } ;

/* Variables and functions */

__attribute__((used)) static int s6e63m0_clear_error(struct s6e63m0 *ctx)
{
	int ret = ctx->error;

	ctx->error = 0;
	return ret;
}