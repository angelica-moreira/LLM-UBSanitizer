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
struct intel_uc_fw {int dummy; } ;

/* Variables and functions */
 scalar_t__ INTEL_UC_FIRMWARE_RUNNING ; 
 scalar_t__ __intel_uc_fw_status (struct intel_uc_fw*) ; 

__attribute__((used)) static inline bool intel_uc_fw_is_running(struct intel_uc_fw *uc_fw)
{
	return __intel_uc_fw_status(uc_fw) == INTEL_UC_FIRMWARE_RUNNING;
}