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
struct aspeed_sig_expr {char const* signal; } ;

/* Variables and functions */

__attribute__((used)) static const char *aspeed_sig_expr_signal(const struct aspeed_sig_expr *expr)
{
	return expr->signal;
}