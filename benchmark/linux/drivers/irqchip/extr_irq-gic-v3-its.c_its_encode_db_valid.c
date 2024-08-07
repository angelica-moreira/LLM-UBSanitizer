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
struct its_cmd_block {int /*<<< orphan*/ * raw_cmd; } ;

/* Variables and functions */
 int /*<<< orphan*/  its_mask_encode (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void its_encode_db_valid(struct its_cmd_block *cmd, bool db_valid)
{
	its_mask_encode(&cmd->raw_cmd[2], db_valid, 0, 0);
}