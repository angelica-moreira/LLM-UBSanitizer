#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int scrambler_onoff; } ;
struct TYPE_6__ {int /*<<< orphan*/  lmc_miireg16; TYPE_1__ ictl; } ;
typedef  TYPE_2__ lmc_softc_t ;

/* Variables and functions */
 int LMC_CTL_OFF ; 
 int LMC_CTL_ON ; 
 int /*<<< orphan*/  LMC_MII16_DS3_SCRAM ; 
 int /*<<< orphan*/  lmc_mii_writereg (TYPE_2__* const,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
lmc_ds3_set_scram (lmc_softc_t * const sc, int ie)
{
  if (ie == LMC_CTL_ON)
    {
      sc->lmc_miireg16 |= LMC_MII16_DS3_SCRAM;
      sc->ictl.scrambler_onoff = LMC_CTL_ON;
    }
  else
    {
      sc->lmc_miireg16 &= ~LMC_MII16_DS3_SCRAM;
      sc->ictl.scrambler_onoff = LMC_CTL_OFF;
    }
  lmc_mii_writereg (sc, 0, 16, sc->lmc_miireg16);
}