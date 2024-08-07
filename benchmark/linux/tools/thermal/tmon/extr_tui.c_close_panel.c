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
typedef  int /*<<< orphan*/  PANEL ;

/* Variables and functions */
 int /*<<< orphan*/  del_panel (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_panel(PANEL *p)
{
	if (p) {
		del_panel(p);
		p = NULL;
	}
}