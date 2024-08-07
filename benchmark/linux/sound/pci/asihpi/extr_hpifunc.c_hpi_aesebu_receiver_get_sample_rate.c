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
 int /*<<< orphan*/  HPI_AESEBURX_SAMPLERATE ; 
 int /*<<< orphan*/  hpi_control_param1_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

u16 hpi_aesebu_receiver_get_sample_rate(u32 h_control, u32 *psample_rate)
{
	return hpi_control_param1_get(h_control, HPI_AESEBURX_SAMPLERATE,
		psample_rate);
}