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
struct TYPE_2__ {int /*<<< orphan*/  i2s_port; int /*<<< orphan*/  type; } ;
struct audio_apbridgea_set_config_request {void* mclk_freq; void* rate; void* format; TYPE_1__ hdr; } ;
typedef  int /*<<< orphan*/  req ;
typedef  int /*<<< orphan*/  __u32 ;
typedef  int /*<<< orphan*/  __u16 ;

/* Variables and functions */
 int /*<<< orphan*/  AUDIO_APBRIDGEA_TYPE_SET_CONFIG ; 
 int /*<<< orphan*/  GB_APB_REQUEST_AUDIO_CONTROL ; 
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 void* cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int gb_hd_output (int /*<<< orphan*/ ,struct audio_apbridgea_set_config_request*,int,int /*<<< orphan*/ ,int) ; 

int gb_audio_apbridgea_set_config(struct gb_connection *connection,
				  __u16 i2s_port, __u32 format, __u32 rate,
				  __u32 mclk_freq)
{
	struct audio_apbridgea_set_config_request req;

	req.hdr.type = AUDIO_APBRIDGEA_TYPE_SET_CONFIG;
	req.hdr.i2s_port = cpu_to_le16(i2s_port);
	req.format = cpu_to_le32(format);
	req.rate = cpu_to_le32(rate);
	req.mclk_freq = cpu_to_le32(mclk_freq);

	return gb_hd_output(connection->hd, &req, sizeof(req),
			    GB_APB_REQUEST_AUDIO_CONTROL, true);
}