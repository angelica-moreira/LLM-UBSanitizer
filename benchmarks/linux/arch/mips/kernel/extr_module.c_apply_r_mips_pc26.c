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
typedef  int /*<<< orphan*/  u32 ;
struct module {int dummy; } ;
typedef  int /*<<< orphan*/  Elf_Addr ;

/* Variables and functions */
 int apply_r_mips_pc (struct module*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int apply_r_mips_pc26(struct module *me, u32 *location,
			     u32 base, Elf_Addr v, bool rela)
{
	return apply_r_mips_pc(me, location, base, v, 26);
}