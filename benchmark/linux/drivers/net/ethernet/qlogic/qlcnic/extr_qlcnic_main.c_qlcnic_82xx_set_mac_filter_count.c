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
typedef  int u16 ;
struct qlcnic_hardware_context {int total_nic_func; int max_mc_count; int max_uc_count; } ;
struct qlcnic_adapter {struct qlcnic_hardware_context* ahw; } ;

/* Variables and functions */
 int QLCNIC_LB_MAX_FILTERS ; 
 int QLCNIC_MAX_MC_COUNT ; 
 int QLCNIC_MAX_UC_COUNT ; 

__attribute__((used)) static void qlcnic_82xx_set_mac_filter_count(struct qlcnic_adapter *adapter)
{
	struct qlcnic_hardware_context *ahw = adapter->ahw;
	u16 act_pci_fn = ahw->total_nic_func;
	u16 count;

	ahw->max_mc_count = QLCNIC_MAX_MC_COUNT;
	if (act_pci_fn <= 2)
		count = (QLCNIC_MAX_UC_COUNT - QLCNIC_MAX_MC_COUNT) /
			 act_pci_fn;
	else
		count = (QLCNIC_LB_MAX_FILTERS - QLCNIC_MAX_MC_COUNT) /
			 act_pci_fn;
	ahw->max_uc_count = count;
}