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
typedef  int u32 ;

/* Variables and functions */
 int /*<<< orphan*/  ETH_ALEN ; 
 int ether_crc_le (int /*<<< orphan*/ ,int const*) ; 

__attribute__((used)) static void genesis_add_filter(u8 filter[8], const u8 *addr)
{
	u32 crc, bit;

	crc = ether_crc_le(ETH_ALEN, addr);
	bit = ~crc & 0x3f;
	filter[bit/8] |= 1 << (bit%8);
}