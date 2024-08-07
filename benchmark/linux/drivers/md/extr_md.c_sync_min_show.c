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
struct mddev {scalar_t__ sync_speed_min; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int speed_min (struct mddev*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,char*) ; 

__attribute__((used)) static ssize_t
sync_min_show(struct mddev *mddev, char *page)
{
	return sprintf(page, "%d (%s)\n", speed_min(mddev),
		       mddev->sync_speed_min ? "local": "system");
}