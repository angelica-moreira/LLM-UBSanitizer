#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_3__ {int /*<<< orphan*/  data; } ;
struct dvb_ca_slot {scalar_t__ slot_state; TYPE_1__ rx_buffer; } ;
struct dvb_ca_private {int next_read_slot; int slot_count; struct dvb_ca_slot* slot_info; } ;

/* Variables and functions */
 scalar_t__ DVB_CA_SLOTSTATE_RUNNING ; 
 int dvb_ringbuffer_pkt_next (TYPE_1__*,int,size_t*) ; 
 int /*<<< orphan*/  dvb_ringbuffer_pkt_read (TYPE_1__*,int,int /*<<< orphan*/ ,int*,int) ; 

__attribute__((used)) static int dvb_ca_en50221_io_read_condition(struct dvb_ca_private *ca,
					    int *result, int *_slot)
{
	int slot;
	int slot_count = 0;
	int idx;
	size_t fraglen;
	int connection_id = -1;
	int found = 0;
	u8 hdr[2];

	slot = ca->next_read_slot;
	while ((slot_count < ca->slot_count) && (!found)) {
		struct dvb_ca_slot *sl = &ca->slot_info[slot];

		if (sl->slot_state != DVB_CA_SLOTSTATE_RUNNING)
			goto nextslot;

		if (!sl->rx_buffer.data)
			return 0;

		idx = dvb_ringbuffer_pkt_next(&sl->rx_buffer, -1, &fraglen);
		while (idx != -1) {
			dvb_ringbuffer_pkt_read(&sl->rx_buffer, idx, 0, hdr, 2);
			if (connection_id == -1)
				connection_id = hdr[0];
			if ((hdr[0] == connection_id) &&
			    ((hdr[1] & 0x80) == 0)) {
				*_slot = slot;
				found = 1;
				break;
			}

			idx = dvb_ringbuffer_pkt_next(&sl->rx_buffer, idx,
						      &fraglen);
		}

nextslot:
		slot = (slot + 1) % ca->slot_count;
		slot_count++;
	}

	ca->next_read_slot = slot;
	return found;
}