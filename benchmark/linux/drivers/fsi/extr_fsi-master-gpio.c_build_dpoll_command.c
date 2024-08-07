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
typedef  int /*<<< orphan*/  uint8_t ;
struct fsi_gpio_msg {scalar_t__ msg; scalar_t__ bits; } ;

/* Variables and functions */
 int /*<<< orphan*/  FSI_CMD_DPOLL ; 
 int /*<<< orphan*/  msg_push_bits (struct fsi_gpio_msg*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msg_push_crc (struct fsi_gpio_msg*) ; 

__attribute__((used)) static void build_dpoll_command(struct fsi_gpio_msg *cmd, uint8_t slave_id)
{
	cmd->bits = 0;
	cmd->msg = 0;

	msg_push_bits(cmd, slave_id, 2);
	msg_push_bits(cmd, FSI_CMD_DPOLL, 3);
	msg_push_crc(cmd);
}