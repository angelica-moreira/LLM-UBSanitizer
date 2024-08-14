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
typedef  unsigned int u64 ;

/* Variables and functions */
 unsigned int BIT_ULL (unsigned int) ; 

__attribute__((used)) static u64 swizzle_bit(unsigned int bit, u64 offset)
{
	return (offset & BIT_ULL(bit)) >> (bit - 6);
}