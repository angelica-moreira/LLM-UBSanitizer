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
struct sd {int dummy; } ;
struct gspca_dev {int dummy; } ;
typedef  int __s32 ;

/* Variables and functions */
 int /*<<< orphan*/  D_CONF ; 
 int /*<<< orphan*/  gspca_dbg (struct gspca_dev*,int /*<<< orphan*/ ,char*,int) ; 
 int hdcs_set_gains (struct sd*,int) ; 

__attribute__((used)) static int hdcs_set_gain(struct gspca_dev *gspca_dev, __s32 val)
{
	gspca_dbg(gspca_dev, D_CONF, "Writing gain %d\n", val);
	return hdcs_set_gains((struct sd *) gspca_dev,
			       val & 0xff);
}