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
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 int /*<<< orphan*/  HPI_GENERIC_EVENT_ENABLE ; 
 int /*<<< orphan*/  hpi_control_param_set (scalar_t__,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 

u16 hpi_tone_detector_set_event_enable(u32 h_control, u32 event_enable)
{
	return hpi_control_param_set(h_control, HPI_GENERIC_EVENT_ENABLE,
		(u32)event_enable, 0);
}