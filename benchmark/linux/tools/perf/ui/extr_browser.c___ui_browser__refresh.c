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
struct ui_browser {int width; int (* refresh ) (struct ui_browser*) ;scalar_t__ nr_entries; scalar_t__ no_samples_msg; scalar_t__ rows; int /*<<< orphan*/  x; scalar_t__ extra_title_lines; scalar_t__ y; scalar_t__ navkeypressed; int /*<<< orphan*/  use_navkeypressed; } ;

/* Variables and functions */
 int /*<<< orphan*/  HE_COLORSET_NORMAL ; 
 int /*<<< orphan*/  SLsmg_fill_region (scalar_t__,int /*<<< orphan*/ ,scalar_t__,int,char) ; 
 int /*<<< orphan*/  __ui__info_window (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ *) ; 
 int stub1 (struct ui_browser*) ; 
 int /*<<< orphan*/  ui_browser__scrollbar_set (struct ui_browser*) ; 
 int /*<<< orphan*/  ui_browser__set_color (struct ui_browser*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int __ui_browser__refresh(struct ui_browser *browser)
{
	int row;
	int width = browser->width;

	row = browser->refresh(browser);
	ui_browser__set_color(browser, HE_COLORSET_NORMAL);

	if (!browser->use_navkeypressed || browser->navkeypressed)
		ui_browser__scrollbar_set(browser);
	else
		width += 1;

	SLsmg_fill_region(browser->y + row + browser->extra_title_lines, browser->x,
			  browser->rows - row, width, ' ');

	if (browser->nr_entries == 0 && browser->no_samples_msg)
		__ui__info_window(NULL, browser->no_samples_msg, NULL);
	return 0;
}