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

/* Variables and functions */
 int partial_crc32 (char const*,int) ; 

__attribute__((used)) static unsigned long crc32(const char *s)
{
	return partial_crc32(s, 0xffffffff) ^ 0xffffffff;
}