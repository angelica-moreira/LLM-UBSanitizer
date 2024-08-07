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
typedef  int u16 ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int /*<<< orphan*/  be16_to_cpup (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void smbus_write_data(u8 *src, u16 *dst, int len)
{
	for (; len > 1; len -= 2) {
		*dst++ = be16_to_cpup((__be16 *)src);
		src += 2;
	}

	if (len)
		*dst = *src << 8;
}