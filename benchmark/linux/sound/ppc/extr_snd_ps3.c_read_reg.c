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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {scalar_t__ mapped_mmio_vaddr; } ;

/* Variables and functions */
 int /*<<< orphan*/  in_be32 (scalar_t__) ; 
 TYPE_1__ the_card ; 

__attribute__((used)) static inline u32 read_reg(unsigned int reg)
{
	return in_be32(the_card.mapped_mmio_vaddr + reg);
}