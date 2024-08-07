#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u64 ;
struct rxe_pkt_info {size_t opcode; scalar_t__ offset; scalar_t__ hdr; } ;
struct TYPE_2__ {scalar_t__* offset; } ;

/* Variables and functions */
 size_t RXE_RETH ; 
 int /*<<< orphan*/  __reth_va (scalar_t__) ; 
 TYPE_1__* rxe_opcode ; 

__attribute__((used)) static inline u64 reth_va(struct rxe_pkt_info *pkt)
{
	return __reth_va(pkt->hdr + pkt->offset
		+ rxe_opcode[pkt->opcode].offset[RXE_RETH]);
}