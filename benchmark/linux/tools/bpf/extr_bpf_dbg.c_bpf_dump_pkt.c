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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  hex_dump (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  rl_printf (char*,scalar_t__,...) ; 

__attribute__((used)) static void bpf_dump_pkt(uint8_t *pkt, uint32_t pkt_caplen, uint32_t pkt_len)
{
	if (pkt_caplen != pkt_len)
		rl_printf("cap: %u, len: %u\n", pkt_caplen, pkt_len);
	else
		rl_printf("len: %u\n", pkt_len);

	hex_dump(pkt, pkt_caplen);
}