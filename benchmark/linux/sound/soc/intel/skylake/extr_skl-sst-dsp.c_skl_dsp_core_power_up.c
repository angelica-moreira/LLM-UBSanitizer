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
struct sst_dsp {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EIO ; 
 int SKL_ADSPCS_CPA_MASK (unsigned int) ; 
 int /*<<< orphan*/  SKL_ADSPCS_SPA_MASK (unsigned int) ; 
 int /*<<< orphan*/  SKL_ADSP_REG_ADSPCS ; 
 int /*<<< orphan*/  SKL_DSP_PU_TO ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,unsigned int) ; 
 int sst_dsp_register_poll (struct sst_dsp*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,char*) ; 
 int sst_dsp_shim_read_unlocked (struct sst_dsp*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sst_dsp_shim_update_bits_unlocked (struct sst_dsp*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int skl_dsp_core_power_up(struct sst_dsp *ctx, unsigned int core_mask)
{
	int ret;

	/* update bits */
	sst_dsp_shim_update_bits_unlocked(ctx, SKL_ADSP_REG_ADSPCS,
			SKL_ADSPCS_SPA_MASK(core_mask),
			SKL_ADSPCS_SPA_MASK(core_mask));

	/* poll with timeout to check if operation successful */
	ret = sst_dsp_register_poll(ctx,
			SKL_ADSP_REG_ADSPCS,
			SKL_ADSPCS_CPA_MASK(core_mask),
			SKL_ADSPCS_CPA_MASK(core_mask),
			SKL_DSP_PU_TO,
			"Power up");

	if ((sst_dsp_shim_read_unlocked(ctx, SKL_ADSP_REG_ADSPCS) &
			SKL_ADSPCS_CPA_MASK(core_mask)) !=
			SKL_ADSPCS_CPA_MASK(core_mask)) {
		dev_err(ctx->dev, "DSP core power up failed: core_mask %x\n",
				core_mask);
		ret = -EIO;
	}

	return ret;
}