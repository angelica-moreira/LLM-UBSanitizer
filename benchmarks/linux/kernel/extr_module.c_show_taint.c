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
struct module_kobject {int /*<<< orphan*/  mod; } ;
struct module_attribute {int dummy; } ;
typedef  size_t ssize_t ;

/* Variables and functions */
 size_t module_flags_taint (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static ssize_t show_taint(struct module_attribute *mattr,
			  struct module_kobject *mk, char *buffer)
{
	size_t l;

	l = module_flags_taint(mk->mod, buffer);
	buffer[l++] = '\n';
	return l;
}