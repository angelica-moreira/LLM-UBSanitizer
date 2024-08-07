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
struct ui_progress {int total; int curr; scalar_t__ size; scalar_t__ title; } ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int /*<<< orphan*/  HE_COLORSET_SELECTED ; 
 int /*<<< orphan*/  SLsmg_draw_box (int,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  SLsmg_fill_region (int,int,int,int,char) ; 
 int /*<<< orphan*/  SLsmg_gotorc (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SLsmg_refresh () ; 
 int /*<<< orphan*/  SLsmg_set_color (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SLsmg_write_string (char*) ; 
 int SLtt_Screen_Cols ; 
 int SLtt_Screen_Rows ; 
 int /*<<< orphan*/  get_title (struct ui_progress*,char*,int) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ui__lock ; 
 int /*<<< orphan*/  ui__refresh_dimensions (int) ; 
 scalar_t__ use_browser ; 

__attribute__((used)) static void tui_progress__update(struct ui_progress *p)
{
	char buf[100], *title = (char *) p->title;
	int bar, y;
	/*
	 * FIXME: We should have a per UI backend way of showing progress,
	 * stdio will just show a percentage as NN%, etc.
	 */
	if (use_browser <= 0)
		return;

	if (p->total == 0)
		return;

	if (p->size) {
		get_title(p, buf, sizeof(buf));
		title = buf;
	}

	ui__refresh_dimensions(false);
	pthread_mutex_lock(&ui__lock);
	y = SLtt_Screen_Rows / 2 - 2;
	SLsmg_set_color(0);
	SLsmg_draw_box(y, 0, 3, SLtt_Screen_Cols);
	SLsmg_gotorc(y++, 1);
	SLsmg_write_string(title);
	SLsmg_fill_region(y, 1, 1, SLtt_Screen_Cols - 2, ' ');
	SLsmg_set_color(HE_COLORSET_SELECTED);
	bar = ((SLtt_Screen_Cols - 2) * p->curr) / p->total;
	SLsmg_fill_region(y, 1, 1, bar, ' ');
	SLsmg_refresh();
	pthread_mutex_unlock(&ui__lock);
}