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
struct stat {int /*<<< orphan*/  st_mode; } ;

/* Variables and functions */
 int /*<<< orphan*/  PERF_HTML_PATH ; 
 int /*<<< orphan*/  S_ISREG (int /*<<< orphan*/ ) ; 
 int asprintf (char**,char*,char const*,char const*) ; 
 int /*<<< orphan*/  mkpath (char*,char const*) ; 
 int /*<<< orphan*/  pr_err (char*,char const*) ; 
 scalar_t__ stat (int /*<<< orphan*/ ,struct stat*) ; 
 char* system_path (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int get_html_page_path(char **page_path, const char *page)
{
	struct stat st;
	const char *html_path = system_path(PERF_HTML_PATH);

	/* Check that we have a perf documentation directory. */
	if (stat(mkpath("%s/perf.html", html_path), &st)
	    || !S_ISREG(st.st_mode)) {
		pr_err("'%s': not a documentation directory.", html_path);
		return -1;
	}

	return asprintf(page_path, "%s/%s.html", html_path, page);
}