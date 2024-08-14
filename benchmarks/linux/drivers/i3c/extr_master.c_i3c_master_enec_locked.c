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
typedef  int /*<<< orphan*/  u8 ;
struct i3c_master_controller {int dummy; } ;

/* Variables and functions */
 int i3c_master_enec_disec_locked (struct i3c_master_controller*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

int i3c_master_enec_locked(struct i3c_master_controller *master, u8 addr,
			   u8 evts)
{
	return i3c_master_enec_disec_locked(master, addr, true, evts);
}