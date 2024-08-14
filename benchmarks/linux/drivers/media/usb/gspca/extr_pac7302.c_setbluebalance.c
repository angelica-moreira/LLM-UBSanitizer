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
struct sd {TYPE_1__* blue_balance; } ;
struct gspca_dev {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  val; } ;

/* Variables and functions */
 int /*<<< orphan*/  reg_w (struct gspca_dev*,int,int) ; 
 int rgbbalance_ctrl_to_reg_value (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void setbluebalance(struct gspca_dev *gspca_dev)
{
	struct sd *sd = (struct sd *) gspca_dev;

	reg_w(gspca_dev, 0xff, 0x00);			/* page 0 */
	reg_w(gspca_dev, 0x03,
	      rgbbalance_ctrl_to_reg_value(sd->blue_balance->val));

	reg_w(gspca_dev, 0xdc, 0x01);
}