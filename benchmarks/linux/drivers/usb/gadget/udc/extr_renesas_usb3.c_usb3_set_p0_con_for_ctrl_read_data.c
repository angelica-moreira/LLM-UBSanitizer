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
struct renesas_usb3 {int dummy; } ;

/* Variables and functions */
 int P0_CON_IN_RES_NORMAL ; 
 int P0_CON_OT_RES_FORCE_STALL ; 
 int P0_CON_ST_RES_FORCE_NRDY ; 
 int /*<<< orphan*/  usb3_set_p0_con_update_res (struct renesas_usb3*,int) ; 

__attribute__((used)) static void usb3_set_p0_con_for_ctrl_read_data(struct renesas_usb3 *usb3)
{
	usb3_set_p0_con_update_res(usb3, P0_CON_ST_RES_FORCE_NRDY |
				   P0_CON_OT_RES_FORCE_STALL |
				   P0_CON_IN_RES_NORMAL);
}