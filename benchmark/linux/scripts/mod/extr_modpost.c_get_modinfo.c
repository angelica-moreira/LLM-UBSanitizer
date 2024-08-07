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
struct elf_info {int dummy; } ;

/* Variables and functions */
 char* get_next_modinfo (struct elf_info*,char const*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static char *get_modinfo(struct elf_info *info, const char *tag)

{
	return get_next_modinfo(info, tag, NULL);
}