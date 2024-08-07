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
struct bdc_req {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct bdc_req*) ; 
 struct bdc_req* to_bdc_req (struct usb_request*) ; 

__attribute__((used)) static void bdc_gadget_free_request(struct usb_ep *_ep,
				     struct usb_request *_req)
{
	struct bdc_req *req;

	req = to_bdc_req(_req);
	kfree(req);
}