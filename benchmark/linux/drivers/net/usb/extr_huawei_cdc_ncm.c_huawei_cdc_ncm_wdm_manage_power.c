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
struct usbnet {int dummy; } ;
struct usb_interface {int dummy; } ;

/* Variables and functions */
 int huawei_cdc_ncm_manage_power (struct usbnet*,int) ; 
 struct usbnet* usb_get_intfdata (struct usb_interface*) ; 

__attribute__((used)) static int huawei_cdc_ncm_wdm_manage_power(struct usb_interface *intf,
					   int status)
{
	struct usbnet *usbnet_dev = usb_get_intfdata(intf);

	/* can be called while disconnecting */
	if (!usbnet_dev)
		return 0;

	return huawei_cdc_ncm_manage_power(usbnet_dev, status);
}