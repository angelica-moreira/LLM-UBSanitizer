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
struct soc_pcmcia_socket {int /*<<< orphan*/  clk; } ;

/* Variables and functions */
 unsigned long clk_get_rate (int /*<<< orphan*/ ) ; 
 int sa1100_pcmcia_set_mecr (struct soc_pcmcia_socket*,unsigned long) ; 

__attribute__((used)) static int
sa1100_pcmcia_set_timing(struct soc_pcmcia_socket *skt)
{
	unsigned long clk = clk_get_rate(skt->clk);

	return sa1100_pcmcia_set_mecr(skt, clk / 1000);
}