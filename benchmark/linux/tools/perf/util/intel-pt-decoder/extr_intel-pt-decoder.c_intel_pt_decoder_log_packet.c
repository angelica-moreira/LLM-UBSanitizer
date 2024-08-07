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
struct intel_pt_decoder {int /*<<< orphan*/  buf; int /*<<< orphan*/  pos; int /*<<< orphan*/  pkt_len; int /*<<< orphan*/  packet; } ;

/* Variables and functions */
 int /*<<< orphan*/  intel_pt_log_packet (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void intel_pt_decoder_log_packet(struct intel_pt_decoder *decoder)
{
	intel_pt_log_packet(&decoder->packet, decoder->pkt_len, decoder->pos,
			    decoder->buf);
}