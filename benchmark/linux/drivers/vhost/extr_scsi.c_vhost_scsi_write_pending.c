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
struct se_cmd {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  target_execute_cmd (struct se_cmd*) ; 

__attribute__((used)) static int vhost_scsi_write_pending(struct se_cmd *se_cmd)
{
	/* Go ahead and process the write immediately */
	target_execute_cmd(se_cmd);
	return 0;
}