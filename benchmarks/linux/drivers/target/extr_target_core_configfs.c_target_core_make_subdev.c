#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct target_backend {int /*<<< orphan*/  tb_dev_stat_cit; int /*<<< orphan*/  tb_dev_alua_tg_pt_gps_cit; int /*<<< orphan*/  tb_dev_wwn_cit; int /*<<< orphan*/  tb_dev_pr_cit; int /*<<< orphan*/  tb_dev_attrib_cit; int /*<<< orphan*/  tb_dev_action_cit; int /*<<< orphan*/  tb_dev_cit; } ;
struct config_item {int dummy; } ;
struct config_group {struct config_item cg_item; } ;
struct t10_alua_tg_pt_gp {struct config_group tg_pt_gp_group; } ;
struct se_hba {int /*<<< orphan*/  hba_access_mutex; struct target_backend* backend; } ;
struct TYPE_8__ {struct config_group alua_tg_pt_gps_group; struct t10_alua_tg_pt_gp* default_tg_pt_gp; } ;
struct TYPE_7__ {struct config_group stat_group; } ;
struct TYPE_6__ {struct config_group t10_wwn_group; } ;
struct TYPE_5__ {struct config_group da_group; } ;
struct se_device {struct config_group dev_group; TYPE_4__ t10_alua; TYPE_3__ dev_stat_grps; TYPE_2__ t10_wwn; struct config_group dev_pr_group; TYPE_1__ dev_attrib; struct config_group dev_action_group; } ;

/* Variables and functions */
 int ENOMEM ; 
 struct config_group* ERR_PTR (int) ; 
 int /*<<< orphan*/  config_group_init_type_name (struct config_group*,char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  configfs_add_default_group (struct config_group*,struct config_group*) ; 
 struct t10_alua_tg_pt_gp* core_alua_allocate_tg_pt_gp (struct se_device*,char*,int) ; 
 struct se_hba* item_to_hba (struct config_item*) ; 
 int mutex_lock_interruptible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct se_device* target_alloc_device (struct se_hba*,char const*) ; 
 int /*<<< orphan*/  target_core_alua_tg_pt_gp_cit ; 
 int /*<<< orphan*/  target_free_device (struct se_device*) ; 
 int /*<<< orphan*/  target_stat_setup_dev_default_groups (struct se_device*) ; 

__attribute__((used)) static struct config_group *target_core_make_subdev(
	struct config_group *group,
	const char *name)
{
	struct t10_alua_tg_pt_gp *tg_pt_gp;
	struct config_item *hba_ci = &group->cg_item;
	struct se_hba *hba = item_to_hba(hba_ci);
	struct target_backend *tb = hba->backend;
	struct se_device *dev;
	int errno = -ENOMEM, ret;

	ret = mutex_lock_interruptible(&hba->hba_access_mutex);
	if (ret)
		return ERR_PTR(ret);

	dev = target_alloc_device(hba, name);
	if (!dev)
		goto out_unlock;

	config_group_init_type_name(&dev->dev_group, name, &tb->tb_dev_cit);

	config_group_init_type_name(&dev->dev_action_group, "action",
			&tb->tb_dev_action_cit);
	configfs_add_default_group(&dev->dev_action_group, &dev->dev_group);

	config_group_init_type_name(&dev->dev_attrib.da_group, "attrib",
			&tb->tb_dev_attrib_cit);
	configfs_add_default_group(&dev->dev_attrib.da_group, &dev->dev_group);

	config_group_init_type_name(&dev->dev_pr_group, "pr",
			&tb->tb_dev_pr_cit);
	configfs_add_default_group(&dev->dev_pr_group, &dev->dev_group);

	config_group_init_type_name(&dev->t10_wwn.t10_wwn_group, "wwn",
			&tb->tb_dev_wwn_cit);
	configfs_add_default_group(&dev->t10_wwn.t10_wwn_group,
			&dev->dev_group);

	config_group_init_type_name(&dev->t10_alua.alua_tg_pt_gps_group,
			"alua", &tb->tb_dev_alua_tg_pt_gps_cit);
	configfs_add_default_group(&dev->t10_alua.alua_tg_pt_gps_group,
			&dev->dev_group);

	config_group_init_type_name(&dev->dev_stat_grps.stat_group,
			"statistics", &tb->tb_dev_stat_cit);
	configfs_add_default_group(&dev->dev_stat_grps.stat_group,
			&dev->dev_group);

	/*
	 * Add core/$HBA/$DEV/alua/default_tg_pt_gp
	 */
	tg_pt_gp = core_alua_allocate_tg_pt_gp(dev, "default_tg_pt_gp", 1);
	if (!tg_pt_gp)
		goto out_free_device;
	dev->t10_alua.default_tg_pt_gp = tg_pt_gp;

	config_group_init_type_name(&tg_pt_gp->tg_pt_gp_group,
			"default_tg_pt_gp", &target_core_alua_tg_pt_gp_cit);
	configfs_add_default_group(&tg_pt_gp->tg_pt_gp_group,
			&dev->t10_alua.alua_tg_pt_gps_group);

	/*
	 * Add core/$HBA/$DEV/statistics/ default groups
	 */
	target_stat_setup_dev_default_groups(dev);

	mutex_unlock(&hba->hba_access_mutex);
	return &dev->dev_group;

out_free_device:
	target_free_device(dev);
out_unlock:
	mutex_unlock(&hba->hba_access_mutex);
	return ERR_PTR(errno);
}