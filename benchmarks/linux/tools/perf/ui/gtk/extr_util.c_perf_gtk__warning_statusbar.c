#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  va_list ;
struct TYPE_3__ {int /*<<< orphan*/  statbar_ctx_id; int /*<<< orphan*/  statbar; } ;

/* Variables and functions */
 int /*<<< orphan*/  GTK_STATUSBAR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  gtk_statusbar_pop (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gtk_statusbar_push (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  perf_gtk__is_active_context (TYPE_1__*) ; 
 TYPE_1__* pgctx ; 
 int /*<<< orphan*/  stderr ; 
 char* strchr (char*,char) ; 
 scalar_t__ vasprintf (char**,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vfprintf (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int perf_gtk__warning_statusbar(const char *format, va_list args)
{
	char *msg, *p;

	if (!perf_gtk__is_active_context(pgctx) ||
	    vasprintf(&msg, format, args) < 0) {
		fprintf(stderr, "Warning:\n");
		vfprintf(stderr, format, args);
		fprintf(stderr, "\n");
		return -1;
	}

	gtk_statusbar_pop(GTK_STATUSBAR(pgctx->statbar),
			  pgctx->statbar_ctx_id);

	/* Only first line can be displayed */
	p = strchr(msg, '\n');
	if (p)
		*p = '\0';

	gtk_statusbar_push(GTK_STATUSBAR(pgctx->statbar),
			   pgctx->statbar_ctx_id, msg);

	free(msg);
	return 0;
}