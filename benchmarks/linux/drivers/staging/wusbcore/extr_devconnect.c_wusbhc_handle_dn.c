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
struct wusbhc {struct device* dev; } ;
struct wusb_dn_hdr {int bType; } ;
struct device {int dummy; } ;

/* Variables and functions */
#define  WUSB_DN_ALIVE 134 
#define  WUSB_DN_CONNECT 133 
#define  WUSB_DN_DISCONNECT 132 
#define  WUSB_DN_EPRDY 131 
#define  WUSB_DN_MASAVAILCHANGED 130 
#define  WUSB_DN_RWAKE 129 
#define  WUSB_DN_SLEEP 128 
 int /*<<< orphan*/  dev_err (struct device*,char*,int,int) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wusbhc_handle_dn_alive (struct wusbhc*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wusbhc_handle_dn_connect (struct wusbhc*,struct wusb_dn_hdr*,size_t) ; 
 int /*<<< orphan*/  wusbhc_handle_dn_disconnect (struct wusbhc*,int /*<<< orphan*/ ) ; 

void wusbhc_handle_dn(struct wusbhc *wusbhc, u8 srcaddr,
		      struct wusb_dn_hdr *dn_hdr, size_t size)
{
	struct device *dev = wusbhc->dev;

	if (size < sizeof(struct wusb_dn_hdr)) {
		dev_err(dev, "DN data shorter than DN header (%d < %d)\n",
			(int)size, (int)sizeof(struct wusb_dn_hdr));
		return;
	}
	switch (dn_hdr->bType) {
	case WUSB_DN_CONNECT:
		wusbhc_handle_dn_connect(wusbhc, dn_hdr, size);
		break;
	case WUSB_DN_ALIVE:
		wusbhc_handle_dn_alive(wusbhc, srcaddr);
		break;
	case WUSB_DN_DISCONNECT:
		wusbhc_handle_dn_disconnect(wusbhc, srcaddr);
		break;
	case WUSB_DN_MASAVAILCHANGED:
	case WUSB_DN_RWAKE:
	case WUSB_DN_SLEEP:
		/* FIXME: handle these DNs. */
		break;
	case WUSB_DN_EPRDY:
		/* The hardware handles these. */
		break;
	default:
		dev_warn(dev, "unknown DN %u (%d octets) from %u\n",
			 dn_hdr->bType, (int)size, srcaddr);
	}
}