#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  stat_group; int /*<<< orphan*/  scsi_att_intr_port_group; int /*<<< orphan*/  scsi_auth_intr_group; } ;
struct se_lun_acl {TYPE_1__ ml_stat_grps; } ;

/* Variables and functions */
 int /*<<< orphan*/  config_group_init_type_name (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  configfs_add_default_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  target_stat_scsi_att_intr_port_cit ; 
 int /*<<< orphan*/  target_stat_scsi_auth_intr_cit ; 

void target_stat_setup_mappedlun_default_groups(struct se_lun_acl *lacl)
{
	config_group_init_type_name(&lacl->ml_stat_grps.scsi_auth_intr_group,
			"scsi_auth_intr", &target_stat_scsi_auth_intr_cit);
	configfs_add_default_group(&lacl->ml_stat_grps.scsi_auth_intr_group,
			&lacl->ml_stat_grps.stat_group);

	config_group_init_type_name(&lacl->ml_stat_grps.scsi_att_intr_port_group,
			"scsi_att_intr_port", &target_stat_scsi_att_intr_port_cit);
	configfs_add_default_group(&lacl->ml_stat_grps.scsi_att_intr_port_group,
			&lacl->ml_stat_grps.stat_group);
}