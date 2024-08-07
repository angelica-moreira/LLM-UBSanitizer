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
struct rtsx_pcr {int extra_caps; int num_slots; int /*<<< orphan*/  ms_pull_ctl_disable_tbl; int /*<<< orphan*/  ms_pull_ctl_enable_tbl; int /*<<< orphan*/  sd_pull_ctl_disable_tbl; int /*<<< orphan*/  sd_pull_ctl_enable_tbl; int /*<<< orphan*/  ic_version; void* rx_initial_phase; void* tx_initial_phase; int /*<<< orphan*/  aspm_en; int /*<<< orphan*/  sd30_drive_sel_3v3; int /*<<< orphan*/  sd30_drive_sel_1v8; int /*<<< orphan*/  card_drive_sel; scalar_t__ flags; int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASPM_L1_EN ; 
 int /*<<< orphan*/  DRIVER_TYPE_B ; 
 int /*<<< orphan*/  DRIVER_TYPE_D ; 
 int EXTRA_CAPS_MMC_8BIT ; 
 int EXTRA_CAPS_SD_SDR104 ; 
 int EXTRA_CAPS_SD_SDR50 ; 
 int /*<<< orphan*/  RTS5209_CARD_DRIVE_DEFAULT ; 
 void* SET_CLOCK_PHASE (int,int,int) ; 
 int /*<<< orphan*/  rts5209_get_ic_version (struct rtsx_pcr*) ; 
 int /*<<< orphan*/  rts5209_ms_pull_ctl_disable_tbl ; 
 int /*<<< orphan*/  rts5209_ms_pull_ctl_enable_tbl ; 
 int /*<<< orphan*/  rts5209_pcr_ops ; 
 int /*<<< orphan*/  rts5209_sd_pull_ctl_disable_tbl ; 
 int /*<<< orphan*/  rts5209_sd_pull_ctl_enable_tbl ; 

void rts5209_init_params(struct rtsx_pcr *pcr)
{
	pcr->extra_caps = EXTRA_CAPS_SD_SDR50 |
		EXTRA_CAPS_SD_SDR104 | EXTRA_CAPS_MMC_8BIT;
	pcr->num_slots = 2;
	pcr->ops = &rts5209_pcr_ops;

	pcr->flags = 0;
	pcr->card_drive_sel = RTS5209_CARD_DRIVE_DEFAULT;
	pcr->sd30_drive_sel_1v8 = DRIVER_TYPE_B;
	pcr->sd30_drive_sel_3v3 = DRIVER_TYPE_D;
	pcr->aspm_en = ASPM_L1_EN;
	pcr->tx_initial_phase = SET_CLOCK_PHASE(27, 27, 16);
	pcr->rx_initial_phase = SET_CLOCK_PHASE(24, 6, 5);

	pcr->ic_version = rts5209_get_ic_version(pcr);
	pcr->sd_pull_ctl_enable_tbl = rts5209_sd_pull_ctl_enable_tbl;
	pcr->sd_pull_ctl_disable_tbl = rts5209_sd_pull_ctl_disable_tbl;
	pcr->ms_pull_ctl_enable_tbl = rts5209_ms_pull_ctl_enable_tbl;
	pcr->ms_pull_ctl_disable_tbl = rts5209_ms_pull_ctl_disable_tbl;
}