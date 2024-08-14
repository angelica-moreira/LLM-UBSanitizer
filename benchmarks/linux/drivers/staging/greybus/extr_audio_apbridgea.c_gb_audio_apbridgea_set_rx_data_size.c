#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct gb_connection {int /*<<< orphan*/  hd; } ;
struct TYPE_2__ {void* i2s_port; int /*<<< orphan*/  type; } ;
struct audio_apbridgea_set_rx_data_size_request {void* size; TYPE_1__ hdr; } ;
typedef  int /*<<< orphan*/  req ;
typedef  int /*<<< orphan*/  __u16 ;

/* Variables and functions */
 int /*<<< orphan*/  AUDIO_APBRIDGEA_TYPE_SET_RX_DATA_SIZE ; 
 int /*<<< orphan*/  GB_APB_REQUEST_AUDIO_CONTROL ; 
 void* cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int gb_hd_output (int /*<<< orphan*/ ,struct audio_apbridgea_set_rx_data_size_request*,int,int /*<<< orphan*/ ,int) ; 

int gb_audio_apbridgea_set_rx_data_size(struct gb_connection *connection,
					__u16 i2s_port, __u16 size)
{
	struct audio_apbridgea_set_rx_data_size_request req;

	req.hdr.type = AUDIO_APBRIDGEA_TYPE_SET_RX_DATA_SIZE;
	req.hdr.i2s_port = cpu_to_le16(i2s_port);
	req.size = cpu_to_le16(size);

	return gb_hd_output(connection->hd, &req, sizeof(req),
			    GB_APB_REQUEST_AUDIO_CONTROL, true);
}