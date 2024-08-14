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
struct dpu_encoder_phys {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPU_DEBUG_VIDENC (struct dpu_encoder_phys*,char*) ; 
 int /*<<< orphan*/  DPU_ERROR (char*) ; 
 int /*<<< orphan*/  kfree (struct dpu_encoder_phys*) ; 

__attribute__((used)) static void dpu_encoder_phys_vid_destroy(struct dpu_encoder_phys *phys_enc)
{
	if (!phys_enc) {
		DPU_ERROR("invalid encoder\n");
		return;
	}

	DPU_DEBUG_VIDENC(phys_enc, "\n");
	kfree(phys_enc);
}