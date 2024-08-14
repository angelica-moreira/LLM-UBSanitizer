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
typedef  int /*<<< orphan*/  u64 ;

/* Variables and functions */
 int /*<<< orphan*/  IVBEP_CB0_MSR_PMON_BOX_FILTER_C6 ; 
 int /*<<< orphan*/  IVBEP_CB0_MSR_PMON_BOX_FILTER_ISOC ; 
 int /*<<< orphan*/  IVBEP_CB0_MSR_PMON_BOX_FILTER_LINK ; 
 int /*<<< orphan*/  IVBEP_CB0_MSR_PMON_BOX_FILTER_NC ; 
 int /*<<< orphan*/  IVBEP_CB0_MSR_PMON_BOX_FILTER_NID ; 
 int /*<<< orphan*/  IVBEP_CB0_MSR_PMON_BOX_FILTER_OPC ; 
 int /*<<< orphan*/  IVBEP_CB0_MSR_PMON_BOX_FILTER_STATE ; 
 int /*<<< orphan*/  IVBEP_CB0_MSR_PMON_BOX_FILTER_TID ; 

__attribute__((used)) static u64 ivbep_cbox_filter_mask(int fields)
{
	u64 mask = 0;

	if (fields & 0x1)
		mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_TID;
	if (fields & 0x2)
		mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_LINK;
	if (fields & 0x4)
		mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_STATE;
	if (fields & 0x8)
		mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_NID;
	if (fields & 0x10) {
		mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_OPC;
		mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_NC;
		mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_C6;
		mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_ISOC;
	}

	return mask;
}