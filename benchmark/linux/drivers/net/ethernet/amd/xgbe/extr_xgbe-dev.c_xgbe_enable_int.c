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
struct xgbe_channel {int /*<<< orphan*/  curr_ier; int /*<<< orphan*/  saved_ier; } ;
typedef  enum xgbe_int { ____Placeholder_xgbe_int } xgbe_int ;

/* Variables and functions */
 int /*<<< orphan*/  DMA_CH_IER ; 
 int /*<<< orphan*/  FBEE ; 
 int /*<<< orphan*/  RBUE ; 
 int /*<<< orphan*/  RIE ; 
 int /*<<< orphan*/  RSE ; 
 int /*<<< orphan*/  TBUE ; 
 int /*<<< orphan*/  TIE ; 
 int /*<<< orphan*/  TXSE ; 
 int /*<<< orphan*/  XGMAC_DMA_IOWRITE (struct xgbe_channel*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  XGMAC_INT_DMA_ALL 136 
#define  XGMAC_INT_DMA_CH_SR_FBE 135 
#define  XGMAC_INT_DMA_CH_SR_RBU 134 
#define  XGMAC_INT_DMA_CH_SR_RI 133 
#define  XGMAC_INT_DMA_CH_SR_RPS 132 
#define  XGMAC_INT_DMA_CH_SR_TBU 131 
#define  XGMAC_INT_DMA_CH_SR_TI 130 
#define  XGMAC_INT_DMA_CH_SR_TI_RI 129 
#define  XGMAC_INT_DMA_CH_SR_TPS 128 
 int /*<<< orphan*/  XGMAC_SET_BITS (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int xgbe_enable_int(struct xgbe_channel *channel,
			   enum xgbe_int int_id)
{
	switch (int_id) {
	case XGMAC_INT_DMA_CH_SR_TI:
		XGMAC_SET_BITS(channel->curr_ier, DMA_CH_IER, TIE, 1);
		break;
	case XGMAC_INT_DMA_CH_SR_TPS:
		XGMAC_SET_BITS(channel->curr_ier, DMA_CH_IER, TXSE, 1);
		break;
	case XGMAC_INT_DMA_CH_SR_TBU:
		XGMAC_SET_BITS(channel->curr_ier, DMA_CH_IER, TBUE, 1);
		break;
	case XGMAC_INT_DMA_CH_SR_RI:
		XGMAC_SET_BITS(channel->curr_ier, DMA_CH_IER, RIE, 1);
		break;
	case XGMAC_INT_DMA_CH_SR_RBU:
		XGMAC_SET_BITS(channel->curr_ier, DMA_CH_IER, RBUE, 1);
		break;
	case XGMAC_INT_DMA_CH_SR_RPS:
		XGMAC_SET_BITS(channel->curr_ier, DMA_CH_IER, RSE, 1);
		break;
	case XGMAC_INT_DMA_CH_SR_TI_RI:
		XGMAC_SET_BITS(channel->curr_ier, DMA_CH_IER, TIE, 1);
		XGMAC_SET_BITS(channel->curr_ier, DMA_CH_IER, RIE, 1);
		break;
	case XGMAC_INT_DMA_CH_SR_FBE:
		XGMAC_SET_BITS(channel->curr_ier, DMA_CH_IER, FBEE, 1);
		break;
	case XGMAC_INT_DMA_ALL:
		channel->curr_ier |= channel->saved_ier;
		break;
	default:
		return -1;
	}

	XGMAC_DMA_IOWRITE(channel, DMA_CH_IER, channel->curr_ier);

	return 0;
}