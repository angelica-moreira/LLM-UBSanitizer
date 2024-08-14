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
typedef  int uint64_t ;
typedef  int uint32_t ;
struct stream_encoder {int dummy; } ;
struct TYPE_3__ {scalar_t__ link_rate; } ;
struct TYPE_4__ {int pix_clk_100hz; } ;
struct encoder_unblank_param {int opp_cnt; TYPE_1__ link_settings; TYPE_2__ timing; } ;
struct dcn10_stream_encoder {int dummy; } ;

/* Variables and functions */
 struct dcn10_stream_encoder* DCN10STRENC_FROM_STRENC (struct stream_encoder*) ; 
 int /*<<< orphan*/  DIG_FE_CNTL ; 
 int /*<<< orphan*/  DIG_START ; 
 int /*<<< orphan*/  DP_STEER_FIFO ; 
 int /*<<< orphan*/  DP_STEER_FIFO_RESET ; 
 int /*<<< orphan*/  DP_VID_M ; 
 int /*<<< orphan*/  DP_VID_M_N_GEN_EN ; 
 int /*<<< orphan*/  DP_VID_N ; 
 int /*<<< orphan*/  DP_VID_N_MUL ; 
 int /*<<< orphan*/  DP_VID_STREAM_CNTL ; 
 int /*<<< orphan*/  DP_VID_STREAM_ENABLE ; 
 int /*<<< orphan*/  DP_VID_TIMING ; 
 int LINK_RATE_REF_FREQ_IN_KHZ ; 
 scalar_t__ LINK_RATE_UNKNOWN ; 
 int /*<<< orphan*/  REG_UPDATE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int div_u64 (int,int) ; 
 scalar_t__ is_two_pixels_per_containter (TYPE_2__*) ; 
 int /*<<< orphan*/  udelay (int) ; 

void enc2_stream_encoder_dp_unblank(
		struct stream_encoder *enc,
		const struct encoder_unblank_param *param)
{
	struct dcn10_stream_encoder *enc1 = DCN10STRENC_FROM_STRENC(enc);

	if (param->link_settings.link_rate != LINK_RATE_UNKNOWN) {
		uint32_t n_vid = 0x8000;
		uint32_t m_vid;
		uint32_t n_multiply = 0;
		uint64_t m_vid_l = n_vid;

		/* YCbCr 4:2:0 : Computed VID_M will be 2X the input rate */
		if (is_two_pixels_per_containter(&param->timing) || param->opp_cnt > 1) {
			/*this logic should be the same in get_pixel_clock_parameters() */
			n_multiply = 1;
		}
		/* M / N = Fstream / Flink
		 * m_vid / n_vid = pixel rate / link rate
		 */

		m_vid_l *= param->timing.pix_clk_100hz / 10;
		m_vid_l = div_u64(m_vid_l,
			param->link_settings.link_rate
				* LINK_RATE_REF_FREQ_IN_KHZ);

		m_vid = (uint32_t) m_vid_l;

		/* enable auto measurement */

		REG_UPDATE(DP_VID_TIMING, DP_VID_M_N_GEN_EN, 0);

		/* auto measurement need 1 full 0x8000 symbol cycle to kick in,
		 * therefore program initial value for Mvid and Nvid
		 */

		REG_UPDATE(DP_VID_N, DP_VID_N, n_vid);

		REG_UPDATE(DP_VID_M, DP_VID_M, m_vid);

		REG_UPDATE_2(DP_VID_TIMING,
				DP_VID_M_N_GEN_EN, 1,
				DP_VID_N_MUL, n_multiply);
	}

	/* set DIG_START to 0x1 to reset FIFO */

	REG_UPDATE(DIG_FE_CNTL, DIG_START, 1);

	/* write 0 to take the FIFO out of reset */

	REG_UPDATE(DIG_FE_CNTL, DIG_START, 0);

	/* switch DP encoder to CRTC data */

	REG_UPDATE(DP_STEER_FIFO, DP_STEER_FIFO_RESET, 0);

	/* wait 100us for DIG/DP logic to prime
	 * (i.e. a few video lines)
	 */
	udelay(100);

	/* the hardware would start sending video at the start of the next DP
	 * frame (i.e. rising edge of the vblank).
	 * NOTE: We used to program DP_VID_STREAM_DIS_DEFER = 2 here, but this
	 * register has no effect on enable transition! HW always guarantees
	 * VID_STREAM enable at start of next frame, and this is not
	 * programmable
	 */

	REG_UPDATE(DP_VID_STREAM_CNTL, DP_VID_STREAM_ENABLE, true);
}