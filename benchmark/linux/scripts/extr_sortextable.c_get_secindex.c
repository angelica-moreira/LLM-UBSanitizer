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
typedef  int /*<<< orphan*/  Elf32_Word ;

/* Variables and functions */
 unsigned int SHN_XINDEX ; 
 unsigned int SPECIAL (unsigned int) ; 
 scalar_t__ is_shndx_special (unsigned int) ; 
 unsigned int r (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static inline unsigned int get_secindex(unsigned int shndx,
					unsigned int sym_offs,
					const Elf32_Word *symtab_shndx_start)
{
	if (is_shndx_special(shndx))
		return SPECIAL(shndx);
	if (shndx != SHN_XINDEX)
		return shndx;
	return r(&symtab_shndx_start[sym_offs]);
}