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
struct ksz_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  port_cfg_diffserv (struct ksz_hw*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sw_dis_diffserv(struct ksz_hw *hw, int port)
{
	port_cfg_diffserv(hw, port, 0);
}