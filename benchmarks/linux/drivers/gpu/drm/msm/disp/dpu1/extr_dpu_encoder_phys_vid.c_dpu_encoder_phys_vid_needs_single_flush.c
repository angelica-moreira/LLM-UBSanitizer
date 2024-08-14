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
struct dpu_encoder_phys {scalar_t__ split_role; } ;

/* Variables and functions */
 scalar_t__ ENC_ROLE_SOLO ; 

__attribute__((used)) static bool dpu_encoder_phys_vid_needs_single_flush(
		struct dpu_encoder_phys *phys_enc)
{
	return phys_enc->split_role != ENC_ROLE_SOLO;
}