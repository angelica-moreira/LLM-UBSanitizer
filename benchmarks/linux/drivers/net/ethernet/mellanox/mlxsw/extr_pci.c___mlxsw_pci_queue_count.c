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
typedef  int /*<<< orphan*/  u8 ;
struct mlxsw_pci_queue_type_group {int /*<<< orphan*/  count; } ;
struct mlxsw_pci {int dummy; } ;
typedef  enum mlxsw_pci_queue_type { ____Placeholder_mlxsw_pci_queue_type } mlxsw_pci_queue_type ;

/* Variables and functions */
 struct mlxsw_pci_queue_type_group* mlxsw_pci_queue_type_group_get (struct mlxsw_pci*,int) ; 

__attribute__((used)) static u8 __mlxsw_pci_queue_count(struct mlxsw_pci *mlxsw_pci,
				  enum mlxsw_pci_queue_type q_type)
{
	struct mlxsw_pci_queue_type_group *queue_group;

	queue_group = mlxsw_pci_queue_type_group_get(mlxsw_pci, q_type);
	return queue_group->count;
}