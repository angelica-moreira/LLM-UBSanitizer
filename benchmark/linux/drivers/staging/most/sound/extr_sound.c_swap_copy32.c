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
 int /*<<< orphan*/  swap32 (int /*<<< orphan*/  const) ; 

__attribute__((used)) static void swap_copy32(u32 *dest, const u32 *source, unsigned int bytes)
{
	unsigned int i = 0;

	while (i < bytes / 4) {
		dest[i] = swap32(source[i]);
		i++;
	}
}