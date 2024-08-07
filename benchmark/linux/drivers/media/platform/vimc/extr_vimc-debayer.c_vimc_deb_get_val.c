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
typedef  int u8 ;

/* Variables and functions */

__attribute__((used)) static unsigned int vimc_deb_get_val(const u8 *bytes,
				     const unsigned int n_bytes)
{
	unsigned int i;
	unsigned int acc = 0;

	for (i = 0; i < n_bytes; i++)
		acc = acc + (bytes[i] << (8 * i));

	return acc;
}