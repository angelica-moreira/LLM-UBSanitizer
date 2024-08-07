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
struct usb_usbvision {size_t dev_model; } ;
struct TYPE_2__ {scalar_t__ codec; } ;

/* Variables and functions */
 scalar_t__ CODEC_WEBCAM ; 
 int /*<<< orphan*/  MAX_USB_HEIGHT ; 
 int /*<<< orphan*/  MAX_USB_WIDTH ; 
 int USBVISION_IS_OPERATIONAL (struct usb_usbvision*) ; 
 TYPE_1__* usbvision_device_data ; 
 int /*<<< orphan*/  usbvision_init_webcam (struct usb_usbvision*) ; 
 int /*<<< orphan*/  usbvision_restart_isoc (struct usb_usbvision*) ; 
 int /*<<< orphan*/  usbvision_set_compress_params (struct usb_usbvision*) ; 
 int /*<<< orphan*/  usbvision_set_dram_settings (struct usb_usbvision*) ; 
 int /*<<< orphan*/  usbvision_set_input (struct usb_usbvision*) ; 
 int /*<<< orphan*/  usbvision_set_output (struct usb_usbvision*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usbvision_set_video_format (struct usb_usbvision*,int) ; 

int usbvision_setup(struct usb_usbvision *usbvision, int format)
{
	if (usbvision_device_data[usbvision->dev_model].codec == CODEC_WEBCAM)
		usbvision_init_webcam(usbvision);
	usbvision_set_video_format(usbvision, format);
	usbvision_set_dram_settings(usbvision);
	usbvision_set_compress_params(usbvision);
	usbvision_set_input(usbvision);
	usbvision_set_output(usbvision, MAX_USB_WIDTH, MAX_USB_HEIGHT);
	usbvision_restart_isoc(usbvision);

	/* cosas del PCM */
	return USBVISION_IS_OPERATIONAL(usbvision);
}