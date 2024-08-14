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
struct usb_interface {int dummy; } ;
struct usb_device_id {int dummy; } ;
struct us_data {char* transport_name; scalar_t__ max_lun; int /*<<< orphan*/  transport_reset; int /*<<< orphan*/  transport; } ;

/* Variables and functions */
 int /*<<< orphan*/  sddr55_host_template ; 
 int /*<<< orphan*/  sddr55_reset ; 
 int /*<<< orphan*/  sddr55_transport ; 
 int sddr55_unusual_dev_list ; 
 struct usb_device_id const* sddr55_usb_ids ; 
 int usb_stor_probe1 (struct us_data**,struct usb_interface*,struct usb_device_id const*,int,int /*<<< orphan*/ *) ; 
 int usb_stor_probe2 (struct us_data*) ; 

__attribute__((used)) static int sddr55_probe(struct usb_interface *intf,
			 const struct usb_device_id *id)
{
	struct us_data *us;
	int result;

	result = usb_stor_probe1(&us, intf, id,
			(id - sddr55_usb_ids) + sddr55_unusual_dev_list,
			&sddr55_host_template);
	if (result)
		return result;

	us->transport_name = "SDDR55";
	us->transport = sddr55_transport;
	us->transport_reset = sddr55_reset;
	us->max_lun = 0;

	result = usb_stor_probe2(us);
	return result;
}