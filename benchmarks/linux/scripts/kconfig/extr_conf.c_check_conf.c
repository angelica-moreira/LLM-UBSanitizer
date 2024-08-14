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
struct symbol {char* name; scalar_t__ type; } ;
struct menu {struct menu* next; struct menu* list; struct symbol* sym; } ;

/* Variables and functions */
 char* CONFIG_ ; 
 scalar_t__ S_STRING ; 
 int /*<<< orphan*/  conf (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  conf_cnt ; 
 int /*<<< orphan*/  free (void*) ; 
 scalar_t__ input_mode ; 
 scalar_t__ listnewconfig ; 
 int /*<<< orphan*/  menu_get_parent_menu (struct menu*) ; 
 int /*<<< orphan*/  menu_is_visible (struct menu*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  rootEntry ; 
 char* sym_escape_string_value (char const*) ; 
 char* sym_get_string_value (struct symbol*) ; 
 scalar_t__ sym_get_tristate_value (struct symbol*) ; 
 int /*<<< orphan*/  sym_has_value (struct symbol*) ; 
 scalar_t__ sym_is_changeable (struct symbol*) ; 
 scalar_t__ sym_is_choice (struct symbol*) ; 
 scalar_t__ yes ; 

__attribute__((used)) static void check_conf(struct menu *menu)
{
	struct symbol *sym;
	struct menu *child;

	if (!menu_is_visible(menu))
		return;

	sym = menu->sym;
	if (sym && !sym_has_value(sym)) {
		if (sym_is_changeable(sym) ||
		    (sym_is_choice(sym) && sym_get_tristate_value(sym) == yes)) {
			if (input_mode == listnewconfig) {
				if (sym->name) {
					const char *str;

					if (sym->type == S_STRING) {
						str = sym_get_string_value(sym);
						str = sym_escape_string_value(str);
						printf("%s%s=%s\n", CONFIG_, sym->name, str);
						free((void *)str);
					} else {
						str = sym_get_string_value(sym);
						printf("%s%s=%s\n", CONFIG_, sym->name, str);
					}
				}
			} else {
				if (!conf_cnt++)
					printf("*\n* Restart config...\n*\n");
				rootEntry = menu_get_parent_menu(menu);
				conf(rootEntry);
			}
		}
	}

	for (child = menu->list; child; child = child->next)
		check_conf(child);
}