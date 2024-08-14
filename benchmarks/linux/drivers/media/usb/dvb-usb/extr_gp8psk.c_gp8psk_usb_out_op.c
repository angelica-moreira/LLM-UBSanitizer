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
struct gp8psk_state {int /*<<< orphan*/  data; } ;
struct dvb_usb_device {int /*<<< orphan*/  usb_mutex; int /*<<< orphan*/  udev; struct gp8psk_state* priv; } ;

/* Variables and functions */
 int EIO ; 
 int USB_DIR_OUT ; 
 int USB_TYPE_VENDOR ; 
 int /*<<< orphan*/  deb_xfer (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  debug_dump (int /*<<< orphan*/ *,int,int /*<<< orphan*/  (*) (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ )) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int usb_control_msg (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  warn (char*) ; 

__attribute__((used)) static int gp8psk_usb_out_op(struct dvb_usb_device *d, u8 req, u16 value,
			     u16 index, u8 *b, int blen)
{
	struct gp8psk_state *st = d->priv;
	int ret;

	deb_xfer("out: req. %x, val: %x, ind: %x, buffer: ",req,value,index);
	debug_dump(b,blen,deb_xfer);

	if (blen > sizeof(st->data))
		return -EIO;

	if ((ret = mutex_lock_interruptible(&d->usb_mutex)))
		return ret;

	memcpy(st->data, b, blen);
	if (usb_control_msg(d->udev,
			usb_sndctrlpipe(d->udev,0),
			req,
			USB_TYPE_VENDOR | USB_DIR_OUT,
			value, index, st->data, blen,
			2000) != blen) {
		warn("usb out operation failed.");
		ret = -EIO;
	} else
		ret = 0;
	mutex_unlock(&d->usb_mutex);

	return ret;
}