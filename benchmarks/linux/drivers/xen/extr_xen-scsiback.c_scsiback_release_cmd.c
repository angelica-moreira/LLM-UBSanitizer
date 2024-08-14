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
struct se_cmd {int /*<<< orphan*/  se_sess; } ;

/* Variables and functions */
 int /*<<< orphan*/  target_free_tag (int /*<<< orphan*/ ,struct se_cmd*) ; 

__attribute__((used)) static void scsiback_release_cmd(struct se_cmd *se_cmd)
{
	target_free_tag(se_cmd->se_sess, se_cmd);
}