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
struct intel_guc_ct_channel {scalar_t__ enabled; } ;
struct intel_guc_ct {struct intel_guc_ct_channel host_channel; } ;
struct intel_guc {int dummy; } ;

/* Variables and functions */
 struct intel_guc* ct_to_guc (struct intel_guc_ct*) ; 
 int ctch_enable (struct intel_guc*,struct intel_guc_ct_channel*) ; 

int intel_guc_ct_enable(struct intel_guc_ct *ct)
{
	struct intel_guc *guc = ct_to_guc(ct);
	struct intel_guc_ct_channel *ctch = &ct->host_channel;

	if (ctch->enabled)
		return 0;

	return ctch_enable(guc, ctch);
}