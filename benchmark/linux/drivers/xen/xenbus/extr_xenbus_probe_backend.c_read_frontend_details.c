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
struct xenbus_device {int dummy; } ;

/* Variables and functions */
 int xenbus_read_otherend_details (struct xenbus_device*,char*,char*) ; 

__attribute__((used)) static int read_frontend_details(struct xenbus_device *xendev)
{
	return xenbus_read_otherend_details(xendev, "frontend-id", "frontend");
}