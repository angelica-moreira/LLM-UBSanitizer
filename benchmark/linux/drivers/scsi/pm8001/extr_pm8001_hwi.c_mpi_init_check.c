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
struct pm8001_hba_info {int /*<<< orphan*/  general_stat_tbl_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  GST_GSTLEN_MPIS_OFFSET ; 
 int GST_MPI_STATE_INIT ; 
 int GST_MPI_STATE_MASK ; 
 int /*<<< orphan*/  MSGU_IBDB_SET ; 
 int SPC_MSGU_CFG_TABLE_UPDATE ; 
 int pm8001_cr32 (struct pm8001_hba_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm8001_cw32 (struct pm8001_hba_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int pm8001_mr32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int mpi_init_check(struct pm8001_hba_info *pm8001_ha)
{
	u32 max_wait_count;
	u32 value;
	u32 gst_len_mpistate;
	/* Write bit0=1 to Inbound DoorBell Register to tell the SPC FW the
	table is updated */
	pm8001_cw32(pm8001_ha, 0, MSGU_IBDB_SET, SPC_MSGU_CFG_TABLE_UPDATE);
	/* wait until Inbound DoorBell Clear Register toggled */
	max_wait_count = 1 * 1000 * 1000;/* 1 sec */
	do {
		udelay(1);
		value = pm8001_cr32(pm8001_ha, 0, MSGU_IBDB_SET);
		value &= SPC_MSGU_CFG_TABLE_UPDATE;
	} while ((value != 0) && (--max_wait_count));

	if (!max_wait_count)
		return -1;
	/* check the MPI-State for initialization */
	gst_len_mpistate =
		pm8001_mr32(pm8001_ha->general_stat_tbl_addr,
		GST_GSTLEN_MPIS_OFFSET);
	if (GST_MPI_STATE_INIT != (gst_len_mpistate & GST_MPI_STATE_MASK))
		return -1;
	/* check MPI Initialization error */
	gst_len_mpistate = gst_len_mpistate >> 16;
	if (0x0000 != gst_len_mpistate)
		return -1;
	return 0;
}