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
 int DIV_ROUND_UP (unsigned int,unsigned int) ; 

__attribute__((used)) static inline unsigned minix_blocks_needed(unsigned bits, unsigned blocksize)
{
	return DIV_ROUND_UP(bits, blocksize * 8);
}