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
typedef  union bfa_port_stats_u {int dummy; } bfa_port_stats_u ;
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_DMA_ALIGN_SZ ; 
 int /*<<< orphan*/  BFA_ROUNDUP (int,int /*<<< orphan*/ ) ; 

u32
bfa_port_meminfo(void)
{
	return BFA_ROUNDUP(sizeof(union bfa_port_stats_u), BFA_DMA_ALIGN_SZ);
}