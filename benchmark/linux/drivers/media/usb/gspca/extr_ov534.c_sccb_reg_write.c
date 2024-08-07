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
typedef  int /*<<< orphan*/  u8 ;
struct gspca_dev {int /*<<< orphan*/  usb_err; } ;

/* Variables and functions */
 int /*<<< orphan*/  D_USBO ; 
 int /*<<< orphan*/  EIO ; 
 int /*<<< orphan*/  OV534_OP_WRITE_3 ; 
 int /*<<< orphan*/  OV534_REG_OPERATION ; 
 int /*<<< orphan*/  OV534_REG_SUBADDR ; 
 int /*<<< orphan*/  OV534_REG_WRITE ; 
 int /*<<< orphan*/  gspca_dbg (struct gspca_dev*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ov534_reg_write (struct gspca_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  sccb_check_status (struct gspca_dev*) ; 

__attribute__((used)) static void sccb_reg_write(struct gspca_dev *gspca_dev, u8 reg, u8 val)
{
	gspca_dbg(gspca_dev, D_USBO, "sccb write: %02x %02x\n", reg, val);
	ov534_reg_write(gspca_dev, OV534_REG_SUBADDR, reg);
	ov534_reg_write(gspca_dev, OV534_REG_WRITE, val);
	ov534_reg_write(gspca_dev, OV534_REG_OPERATION, OV534_OP_WRITE_3);

	if (!sccb_check_status(gspca_dev)) {
		pr_err("sccb_reg_write failed\n");
		gspca_dev->usb_err = -EIO;
	}
}