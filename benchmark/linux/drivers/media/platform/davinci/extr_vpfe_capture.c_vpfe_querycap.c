#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct vpfe_device {TYPE_1__* cfg; int /*<<< orphan*/  v4l2_dev; } ;
struct v4l2_capability {int /*<<< orphan*/  card; int /*<<< orphan*/  bus_info; int /*<<< orphan*/  driver; } ;
struct file {int dummy; } ;
struct TYPE_2__ {char* card_name; } ;

/* Variables and functions */
 char* CAPTURE_DRV_NAME ; 
 int /*<<< orphan*/  debug ; 
 int /*<<< orphan*/  strscpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  v4l2_dbg (int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*) ; 
 struct vpfe_device* video_drvdata (struct file*) ; 

__attribute__((used)) static int vpfe_querycap(struct file *file, void  *priv,
			       struct v4l2_capability *cap)
{
	struct vpfe_device *vpfe_dev = video_drvdata(file);

	v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_querycap\n");

	strscpy(cap->driver, CAPTURE_DRV_NAME, sizeof(cap->driver));
	strscpy(cap->bus_info, "VPFE", sizeof(cap->bus_info));
	strscpy(cap->card, vpfe_dev->cfg->card_name, sizeof(cap->card));
	return 0;
}