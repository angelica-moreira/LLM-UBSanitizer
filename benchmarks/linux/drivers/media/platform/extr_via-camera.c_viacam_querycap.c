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
struct v4l2_capability {int /*<<< orphan*/  bus_info; int /*<<< orphan*/  card; int /*<<< orphan*/  driver; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  strscpy (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static int viacam_querycap(struct file *filp, void *priv,
		struct v4l2_capability *cap)
{
	strscpy(cap->driver, "via-camera", sizeof(cap->driver));
	strscpy(cap->card, "via-camera", sizeof(cap->card));
	strscpy(cap->bus_info, "platform:via-camera", sizeof(cap->bus_info));
	return 0;
}