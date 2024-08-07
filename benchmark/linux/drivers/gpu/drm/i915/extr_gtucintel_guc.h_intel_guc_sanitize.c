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
struct intel_guc {scalar_t__ mmio_msg; int /*<<< orphan*/  fw; } ;

/* Variables and functions */
 int /*<<< orphan*/  intel_uc_fw_sanitize (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int intel_guc_sanitize(struct intel_guc *guc)
{
	intel_uc_fw_sanitize(&guc->fw);
	guc->mmio_msg = 0;

	return 0;
}