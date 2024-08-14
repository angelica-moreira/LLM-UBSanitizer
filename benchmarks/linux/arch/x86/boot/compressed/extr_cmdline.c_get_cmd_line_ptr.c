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
typedef  int u64 ;
struct TYPE_3__ {unsigned long cmd_line_ptr; } ;
struct TYPE_4__ {scalar_t__ ext_cmd_line_ptr; TYPE_1__ hdr; } ;

/* Variables and functions */
 TYPE_2__* boot_params ; 

unsigned long get_cmd_line_ptr(void)
{
	unsigned long cmd_line_ptr = boot_params->hdr.cmd_line_ptr;

	cmd_line_ptr |= (u64)boot_params->ext_cmd_line_ptr << 32;

	return cmd_line_ptr;
}