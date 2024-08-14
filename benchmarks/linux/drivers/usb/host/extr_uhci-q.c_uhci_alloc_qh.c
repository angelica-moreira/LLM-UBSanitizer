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
struct usb_host_endpoint {int /*<<< orphan*/  desc; struct uhci_qh* hcpriv; } ;
struct usb_device {int /*<<< orphan*/  speed; } ;
struct uhci_qh {int type; int load; int /*<<< orphan*/  state; struct usb_device* udev; struct usb_host_endpoint* hep; int /*<<< orphan*/  dummy_td; int /*<<< orphan*/  node; int /*<<< orphan*/  queue; void* link; void* element; int /*<<< orphan*/  dma_handle; } ;
struct uhci_hcd {int /*<<< orphan*/  qh_pool; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  QH_STATE_ACTIVE ; 
 int /*<<< orphan*/  QH_STATE_IDLE ; 
 void* UHCI_PTR_TERM (struct uhci_hcd*) ; 
 int USB_ENDPOINT_XFER_INT ; 
 int USB_ENDPOINT_XFER_ISOC ; 
 int /*<<< orphan*/  dma_pool_free (int /*<<< orphan*/ ,struct uhci_qh*,int /*<<< orphan*/ ) ; 
 struct uhci_qh* dma_pool_zalloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uhci_alloc_td (struct uhci_hcd*) ; 
 int usb_calc_bus_time (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_endpoint_dir_in (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_endpoint_maxp (int /*<<< orphan*/ *) ; 
 int usb_endpoint_type (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct uhci_qh *uhci_alloc_qh(struct uhci_hcd *uhci,
		struct usb_device *udev, struct usb_host_endpoint *hep)
{
	dma_addr_t dma_handle;
	struct uhci_qh *qh;

	qh = dma_pool_zalloc(uhci->qh_pool, GFP_ATOMIC, &dma_handle);
	if (!qh)
		return NULL;

	qh->dma_handle = dma_handle;

	qh->element = UHCI_PTR_TERM(uhci);
	qh->link = UHCI_PTR_TERM(uhci);

	INIT_LIST_HEAD(&qh->queue);
	INIT_LIST_HEAD(&qh->node);

	if (udev) {		/* Normal QH */
		qh->type = usb_endpoint_type(&hep->desc);
		if (qh->type != USB_ENDPOINT_XFER_ISOC) {
			qh->dummy_td = uhci_alloc_td(uhci);
			if (!qh->dummy_td) {
				dma_pool_free(uhci->qh_pool, qh, dma_handle);
				return NULL;
			}
		}
		qh->state = QH_STATE_IDLE;
		qh->hep = hep;
		qh->udev = udev;
		hep->hcpriv = qh;

		if (qh->type == USB_ENDPOINT_XFER_INT ||
				qh->type == USB_ENDPOINT_XFER_ISOC)
			qh->load = usb_calc_bus_time(udev->speed,
					usb_endpoint_dir_in(&hep->desc),
					qh->type == USB_ENDPOINT_XFER_ISOC,
					usb_endpoint_maxp(&hep->desc))
				/ 1000 + 1;

	} else {		/* Skeleton QH */
		qh->state = QH_STATE_ACTIVE;
		qh->type = -1;
	}
	return qh;
}