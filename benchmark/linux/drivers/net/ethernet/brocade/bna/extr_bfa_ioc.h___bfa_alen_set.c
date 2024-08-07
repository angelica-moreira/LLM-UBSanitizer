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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct bfi_alen {int /*<<< orphan*/  al_addr; int /*<<< orphan*/  al_len; } ;

/* Variables and functions */
 int /*<<< orphan*/  bfa_dma_be_addr_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
__bfa_alen_set(struct bfi_alen *alen, u32 len, u64 pa)
{
	alen->al_len = cpu_to_be32(len);
	bfa_dma_be_addr_set(alen->al_addr, pa);
}