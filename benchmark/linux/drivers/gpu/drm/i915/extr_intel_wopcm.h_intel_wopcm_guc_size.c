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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int /*<<< orphan*/  size; } ;
struct intel_wopcm {TYPE_1__ guc; } ;

/* Variables and functions */

__attribute__((used)) static inline u32 intel_wopcm_guc_size(struct intel_wopcm *wopcm)
{
	return wopcm->guc.size;
}