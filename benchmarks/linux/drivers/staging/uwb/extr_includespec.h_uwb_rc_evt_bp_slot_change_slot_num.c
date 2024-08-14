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
struct uwb_rc_evt_bp_slot_change {int slot_info; } ;

/* Variables and functions */

__attribute__((used)) static inline int uwb_rc_evt_bp_slot_change_slot_num(
	const struct uwb_rc_evt_bp_slot_change *evt)
{
	return evt->slot_info & 0x7f;
}