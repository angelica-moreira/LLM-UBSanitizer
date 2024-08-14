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
typedef  int /*<<< orphan*/  u64 ;

/* Variables and functions */
 int /*<<< orphan*/  lowpan_iphc_ctx_is_compression (void*) ; 

__attribute__((used)) static int lowpan_ctx_flag_c_get(void *data, u64 *val)
{
	*val = lowpan_iphc_ctx_is_compression(data);
	return 0;
}