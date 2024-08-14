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
struct ui_browser {int /*<<< orphan*/  width; scalar_t__ priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  HE_COLORSET_NORMAL ; 
 int /*<<< orphan*/  HE_COLORSET_SELECTED ; 
 unsigned long strlen (char*) ; 
 int ui_browser__is_current_entry (struct ui_browser*,int) ; 
 int /*<<< orphan*/  ui_browser__set_color (struct ui_browser*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ui_browser__write_nstring (struct ui_browser*,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ui_browser__argv_write(struct ui_browser *browser,
				   void *entry, int row)
{
	char **arg = entry;
	char *str = *arg;
	char empty[] = " ";
	bool current_entry = ui_browser__is_current_entry(browser, row);
	unsigned long offset = (unsigned long)browser->priv;

	if (offset >= strlen(str))
		str = empty;
	else
		str = str + offset;

	ui_browser__set_color(browser, current_entry ? HE_COLORSET_SELECTED :
						       HE_COLORSET_NORMAL);

	ui_browser__write_nstring(browser, str, browser->width);
}