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
struct pmcraid_cmd {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PMCRAID_HCAM_CODE_LOG_DATA ; 
 int /*<<< orphan*/  pmcraid_cancel_ccn ; 
 int /*<<< orphan*/  pmcraid_cancel_hcam (struct pmcraid_cmd*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pmcraid_cancel_ldn(struct pmcraid_cmd *cmd)
{
	pmcraid_cancel_hcam(cmd,
			    PMCRAID_HCAM_CODE_LOG_DATA,
			    pmcraid_cancel_ccn);
}