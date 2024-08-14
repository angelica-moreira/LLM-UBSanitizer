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
struct platform_device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int USB_PHY_TYPE_DEVICE ; 
 int s3c_usb_otgphy_exit (struct platform_device*) ; 

int s5p_usb_phy_exit(struct platform_device *pdev, int type)
{
	if (type == USB_PHY_TYPE_DEVICE)
		return s3c_usb_otgphy_exit(pdev);

	return -EINVAL;
}