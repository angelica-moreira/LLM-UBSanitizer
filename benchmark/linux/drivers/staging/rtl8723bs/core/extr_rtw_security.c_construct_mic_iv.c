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
typedef  scalar_t__ uint ;
typedef  int u8 ;
typedef  int sint ;

/* Variables and functions */
 int BIT (int) ; 
 scalar_t__ WIFI_MGT_TYPE ; 

__attribute__((used)) static void construct_mic_iv(
	u8 *mic_iv,
	sint qc_exists,
	sint a4_exists,
	u8 *mpdu,
	uint payload_length,
	u8 *pn_vector,
	uint frtype/*  add for CONFIG_IEEE80211W, none 11w also can use */
)
{
		sint i;

		mic_iv[0] = 0x59;

		if (qc_exists && a4_exists)
			mic_iv[1] = mpdu[30] & 0x0f;    /* QoS_TC           */

		if (qc_exists && !a4_exists)
			mic_iv[1] = mpdu[24] & 0x0f;   /* mute bits 7-4    */

		if (!qc_exists)
			mic_iv[1] = 0x00;

		/* 802.11w management frame should set management bit(4) */
		if (frtype == WIFI_MGT_TYPE)
			mic_iv[1] |= BIT(4);

		for (i = 2; i < 8; i++)
			mic_iv[i] = mpdu[i + 8];   /* mic_iv[2:7] = A2[0:5] = mpdu[10:15] */
		#ifdef CONSISTENT_PN_ORDER
		for (i = 8; i < 14; i++)
			mic_iv[i] = pn_vector[i - 8];           /* mic_iv[8:13] = PN[0:5] */
		#else
		for (i = 8; i < 14; i++)
			mic_iv[i] = pn_vector[13 - i];          /* mic_iv[8:13] = PN[5:0] */
		#endif
		mic_iv[14] = (unsigned char) (payload_length / 256);
		mic_iv[15] = (unsigned char) (payload_length % 256);
}