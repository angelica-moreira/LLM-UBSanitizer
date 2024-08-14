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
struct usb_request {int dummy; } ;
struct usb_ep {int dummy; } ;
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 struct usb_request* __renesas_usb3_ep_alloc_request (int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct usb_request *renesas_usb3_ep_alloc_request(struct usb_ep *_ep,
							 gfp_t gfp_flags)
{
	return __renesas_usb3_ep_alloc_request(gfp_flags);
}