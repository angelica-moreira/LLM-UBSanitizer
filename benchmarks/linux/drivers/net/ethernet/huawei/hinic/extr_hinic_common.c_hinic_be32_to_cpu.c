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

/* Variables and functions */
 int /*<<< orphan*/  be32_to_cpu (int /*<<< orphan*/ ) ; 

void hinic_be32_to_cpu(void *data, int len)
{
	u32 *mem = data;
	int i;

	len = len / sizeof(u32);

	for (i = 0; i < len; i++) {
		*mem = be32_to_cpu(*mem);
		mem++;
	}
}