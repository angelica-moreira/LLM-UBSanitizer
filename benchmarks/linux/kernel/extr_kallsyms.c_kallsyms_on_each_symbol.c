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

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (char*) ; 
 int KSYM_NAME_LEN ; 
 unsigned int kallsyms_expand_symbol (unsigned int,char*,int /*<<< orphan*/ ) ; 
 unsigned long kallsyms_num_syms ; 
 unsigned long kallsyms_sym_address (unsigned long) ; 
 int module_kallsyms_on_each_symbol (int (*) (void*,char const*,struct module*,unsigned long),void*) ; 

int kallsyms_on_each_symbol(int (*fn)(void *, const char *, struct module *,
				      unsigned long),
			    void *data)
{
	char namebuf[KSYM_NAME_LEN];
	unsigned long i;
	unsigned int off;
	int ret;

	for (i = 0, off = 0; i < kallsyms_num_syms; i++) {
		off = kallsyms_expand_symbol(off, namebuf, ARRAY_SIZE(namebuf));
		ret = fn(data, namebuf, NULL, kallsyms_sym_address(i));
		if (ret != 0)
			return ret;
	}
	return module_kallsyms_on_each_symbol(fn, data);
}