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
typedef  int u32 ;
struct sst_dsp {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CNL_ADSP_REG_HIPCIDR ; 
 int CNL_ADSP_REG_HIPCIDR_BUSY ; 
 int sst_dsp_shim_read_unlocked (struct sst_dsp*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool cnl_ipc_is_dsp_busy(struct sst_dsp *dsp)
{
	u32 hipcidr;

	hipcidr = sst_dsp_shim_read_unlocked(dsp, CNL_ADSP_REG_HIPCIDR);

	return (hipcidr & CNL_ADSP_REG_HIPCIDR_BUSY);
}