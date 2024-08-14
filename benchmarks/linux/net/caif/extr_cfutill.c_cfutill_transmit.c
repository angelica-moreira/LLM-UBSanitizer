#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_3__ {int /*<<< orphan*/  id; } ;
struct cfsrvl {int /*<<< orphan*/  dev_info; TYPE_1__ layer; } ;
struct cfpkt {int dummy; } ;
struct cflayer {TYPE_2__* dn; } ;
struct caif_payload_info {int hdr_len; int /*<<< orphan*/ * dev_info; int /*<<< orphan*/  channel_id; } ;
struct TYPE_4__ {int (* transmit ) (TYPE_2__*,struct cfpkt*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  caif_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cfpkt_add_head (struct cfpkt*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  cfpkt_destroy (struct cfpkt*) ; 
 struct caif_payload_info* cfpkt_info (struct cfpkt*) ; 
 int /*<<< orphan*/  cfsrvl_ready (struct cfsrvl*,int*) ; 
 struct cfsrvl* container_obj (struct cflayer*) ; 
 int stub1 (TYPE_2__*,struct cfpkt*) ; 

__attribute__((used)) static int cfutill_transmit(struct cflayer *layr, struct cfpkt *pkt)
{
	u8 zero = 0;
	struct caif_payload_info *info;
	int ret;
	struct cfsrvl *service = container_obj(layr);
	caif_assert(layr != NULL);
	caif_assert(layr->dn != NULL);
	caif_assert(layr->dn->transmit != NULL);

	if (!cfsrvl_ready(service, &ret)) {
		cfpkt_destroy(pkt);
		return ret;
	}

	cfpkt_add_head(pkt, &zero, 1);
	/* Add info for MUX-layer to route the packet out. */
	info = cfpkt_info(pkt);
	info->channel_id = service->layer.id;
	/*
	 * To optimize alignment, we add up the size of CAIF header before
	 * payload.
	 */
	info->hdr_len = 1;
	info->dev_info = &service->dev_info;
	return layr->dn->transmit(layr->dn, pkt);
}