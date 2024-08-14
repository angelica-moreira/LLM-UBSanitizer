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
struct xenbus_watch {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  xenbus_otherend_changed (struct xenbus_watch*,char const*,char const*,int) ; 

__attribute__((used)) static void backend_changed(struct xenbus_watch *watch,
			    const char *path, const char *token)
{
	xenbus_otherend_changed(watch, path, token, 1);
}