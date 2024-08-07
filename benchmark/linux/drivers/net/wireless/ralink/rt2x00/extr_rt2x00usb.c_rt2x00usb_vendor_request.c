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
typedef  int /*<<< orphan*/  u16 ;
struct usb_device {int dummy; } ;
struct rt2x00_dev {int /*<<< orphan*/  flags; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEVICE_STATE_PRESENT ; 
 int ENODEV ; 
 int /*<<< orphan*/  const USB_VENDOR_REQUEST_IN ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 unsigned long jiffies ; 
 unsigned long msecs_to_jiffies (int const) ; 
 int /*<<< orphan*/  rt2x00_err (struct rt2x00_dev*,char*,int /*<<< orphan*/  const,int /*<<< orphan*/  const,int) ; 
 scalar_t__ rt2x00usb_check_usb_error (struct rt2x00_dev*,int) ; 
 int /*<<< orphan*/  test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ time_before (unsigned long,unsigned long) ; 
 struct usb_device* to_usb_device_intf (int /*<<< orphan*/ ) ; 
 int usb_control_msg (struct usb_device*,unsigned int,int /*<<< orphan*/  const,int /*<<< orphan*/  const,int /*<<< orphan*/  const,int /*<<< orphan*/  const,void*,int /*<<< orphan*/  const,int const) ; 
 unsigned int usb_rcvctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 
 unsigned int usb_sndctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 

int rt2x00usb_vendor_request(struct rt2x00_dev *rt2x00dev,
			     const u8 request, const u8 requesttype,
			     const u16 offset, const u16 value,
			     void *buffer, const u16 buffer_length,
			     const int timeout)
{
	struct usb_device *usb_dev = to_usb_device_intf(rt2x00dev->dev);
	int status;
	unsigned int pipe =
	    (requesttype == USB_VENDOR_REQUEST_IN) ?
	    usb_rcvctrlpipe(usb_dev, 0) : usb_sndctrlpipe(usb_dev, 0);
	unsigned long expire = jiffies + msecs_to_jiffies(timeout);

	if (!test_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags))
		return -ENODEV;

	do {
		status = usb_control_msg(usb_dev, pipe, request, requesttype,
					 value, offset, buffer, buffer_length,
					 timeout / 2);
		if (status >= 0)
			return 0;

		if (rt2x00usb_check_usb_error(rt2x00dev, status)) {
			/* Device has disappeared. */
			clear_bit(DEVICE_STATE_PRESENT, &rt2x00dev->flags);
			break;
		}
	} while (time_before(jiffies, expire));

	rt2x00_err(rt2x00dev,
		   "Vendor Request 0x%02x failed for offset 0x%04x with error %d\n",
		   request, offset, status);

	return status;
}