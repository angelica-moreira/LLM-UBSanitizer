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
struct kernel_param {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  RPC_MAX_RESVPORT ; 
 int /*<<< orphan*/  RPC_MIN_RESVPORT ; 
 int param_set_uint_minmax (char const*,struct kernel_param const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int param_set_portnr(const char *val, const struct kernel_param *kp)
{
	return param_set_uint_minmax(val, kp,
			RPC_MIN_RESVPORT,
			RPC_MAX_RESVPORT);
}