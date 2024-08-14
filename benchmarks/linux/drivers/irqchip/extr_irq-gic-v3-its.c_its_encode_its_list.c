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
typedef  int /*<<< orphan*/  u16 ;
struct its_cmd_block {int /*<<< orphan*/ * raw_cmd; } ;

/* Variables and functions */
 int /*<<< orphan*/  its_mask_encode (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void its_encode_its_list(struct its_cmd_block *cmd, u16 its_list)
{
	its_mask_encode(&cmd->raw_cmd[1], its_list, 15, 0);
}