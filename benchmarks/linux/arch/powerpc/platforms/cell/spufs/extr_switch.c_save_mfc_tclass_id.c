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
struct TYPE_2__ {int /*<<< orphan*/  mfc_tclass_id_RW; } ;
struct spu_state {TYPE_1__ priv1; } ;
struct spu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  spu_mfc_tclass_id_get (struct spu*) ; 

__attribute__((used)) static inline void save_mfc_tclass_id(struct spu_state *csa, struct spu *spu)
{
	/* Save, Step 25:
	 *     Save the MFC_TCLASS_ID register in
	 *     the CSA.
	 */
	csa->priv1.mfc_tclass_id_RW = spu_mfc_tclass_id_get(spu);
}