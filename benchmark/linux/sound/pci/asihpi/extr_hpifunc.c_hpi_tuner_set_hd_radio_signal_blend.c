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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 int /*<<< orphan*/  HPI_TUNER_HDRADIO_BLEND ; 
 int /*<<< orphan*/  hpi_control_param_set (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 

u16 hpi_tuner_set_hd_radio_signal_blend(u32 h_control, const u32 blend)
{
	return hpi_control_param_set(h_control, HPI_TUNER_HDRADIO_BLEND,
		blend, 0);
}