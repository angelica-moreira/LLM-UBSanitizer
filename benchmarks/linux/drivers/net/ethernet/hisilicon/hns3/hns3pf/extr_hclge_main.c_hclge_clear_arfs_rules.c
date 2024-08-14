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
struct hnae3_handle {int dummy; } ;
struct hclge_vport {struct hclge_dev* back; } ;
struct hclge_dev {scalar_t__ fd_active_type; } ;

/* Variables and functions */
 scalar_t__ HCLGE_FD_ARFS_ACTIVE ; 
 int /*<<< orphan*/  hclge_del_all_fd_entries (struct hnae3_handle*,int) ; 
 struct hclge_vport* hclge_get_vport (struct hnae3_handle*) ; 

__attribute__((used)) static void hclge_clear_arfs_rules(struct hnae3_handle *handle)
{
#ifdef CONFIG_RFS_ACCEL
	struct hclge_vport *vport = hclge_get_vport(handle);
	struct hclge_dev *hdev = vport->back;

	if (hdev->fd_active_type == HCLGE_FD_ARFS_ACTIVE)
		hclge_del_all_fd_entries(handle, true);
#endif
}