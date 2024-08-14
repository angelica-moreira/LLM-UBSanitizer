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
struct TYPE_2__ {int /*<<< orphan*/  mfc_sr1_RW; } ;
struct spu_state {TYPE_1__ priv1; } ;
struct spu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  eieio () ; 
 int /*<<< orphan*/  spu_mfc_sr1_set (struct spu*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void restore_mfc_sr1(struct spu_state *csa, struct spu *spu)
{
	/* Restore, Step 69:
	 *     Restore the MFC_SR1 register from CSA.
	 */
	spu_mfc_sr1_set(spu, csa->priv1.mfc_sr1_RW);
	eieio();
}