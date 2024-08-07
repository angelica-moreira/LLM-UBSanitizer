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
struct gspca_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPIA_COMMAND_GetCPIAVersion ; 
 int /*<<< orphan*/  CPIA_COMMAND_GetPnPID ; 
 int do_command (struct gspca_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int get_version_information(struct gspca_dev *gspca_dev)
{
	int ret;

	/* GetCPIAVersion */
	ret = do_command(gspca_dev, CPIA_COMMAND_GetCPIAVersion, 0, 0, 0, 0);
	if (ret)
		return ret;

	/* GetPnPID */
	return do_command(gspca_dev, CPIA_COMMAND_GetPnPID, 0, 0, 0, 0);
}