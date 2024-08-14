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
struct usb_device {int dummy; } ;
struct usb_dev_state {int dummy; } ;

/* Variables and functions */
 int EBUSY ; 
 int find_port_owner (struct usb_device*,unsigned int,struct usb_dev_state***) ; 

int usb_hub_claim_port(struct usb_device *hdev, unsigned port1,
		       struct usb_dev_state *owner)
{
	int rc;
	struct usb_dev_state **powner;

	rc = find_port_owner(hdev, port1, &powner);
	if (rc)
		return rc;
	if (*powner)
		return -EBUSY;
	*powner = owner;
	return rc;
}