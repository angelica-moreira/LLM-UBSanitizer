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
struct mem_ctl_info {int dummy; } ;
struct i5000_error_info {int ferr_fat_fbd; int /*<<< orphan*/  nrecmemb; int /*<<< orphan*/  nrecmema; } ;
typedef  int /*<<< orphan*/  msg ;

/* Variables and functions */
 int /*<<< orphan*/  EDAC_MC_LABEL_LEN ; 
 int EXTRACT_FBDCHAN_INDX (int) ; 
#define  FERR_FAT_M1ERR 130 
#define  FERR_FAT_M2ERR 129 
#define  FERR_FAT_M3ERR 128 
 int FERR_FAT_MASK ; 
 int /*<<< orphan*/  HW_EVENT_ERR_FATAL ; 
 int NREC_BANK (int /*<<< orphan*/ ) ; 
 int NREC_CAS (int /*<<< orphan*/ ) ; 
 int NREC_RANK (int /*<<< orphan*/ ) ; 
 int NREC_RAS (int /*<<< orphan*/ ) ; 
 int NREC_RDWR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  edac_dbg (int /*<<< orphan*/ ,char*,int,int,int,char*,int,int) ; 
 int /*<<< orphan*/  edac_mc_handle_error (int /*<<< orphan*/ ,struct mem_ctl_info*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int,char*,char*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int,int,int,int,char*) ; 

__attribute__((used)) static void i5000_process_fatal_error_info(struct mem_ctl_info *mci,
					struct i5000_error_info *info,
					int handle_errors)
{
	char msg[EDAC_MC_LABEL_LEN + 1 + 160];
	char *specific = NULL;
	u32 allErrors;
	int channel;
	int bank;
	int rank;
	int rdwr;
	int ras, cas;

	/* mask off the Error bits that are possible */
	allErrors = (info->ferr_fat_fbd & FERR_FAT_MASK);
	if (!allErrors)
		return;		/* if no error, return now */

	channel = EXTRACT_FBDCHAN_INDX(info->ferr_fat_fbd);

	/* Use the NON-Recoverable macros to extract data */
	bank = NREC_BANK(info->nrecmema);
	rank = NREC_RANK(info->nrecmema);
	rdwr = NREC_RDWR(info->nrecmema);
	ras = NREC_RAS(info->nrecmemb);
	cas = NREC_CAS(info->nrecmemb);

	edac_dbg(0, "\t\tCSROW= %d  Channel= %d (DRAM Bank= %d rdwr= %s ras= %d cas= %d)\n",
		 rank, channel, bank,
		 rdwr ? "Write" : "Read", ras, cas);

	/* Only 1 bit will be on */
	switch (allErrors) {
	case FERR_FAT_M1ERR:
		specific = "Alert on non-redundant retry or fast "
				"reset timeout";
		break;
	case FERR_FAT_M2ERR:
		specific = "Northbound CRC error on non-redundant "
				"retry";
		break;
	case FERR_FAT_M3ERR:
		{
		static int done;

		/*
		 * This error is generated to inform that the intelligent
		 * throttling is disabled and the temperature passed the
		 * specified middle point. Since this is something the BIOS
		 * should take care of, we'll warn only once to avoid
		 * worthlessly flooding the log.
		 */
		if (done)
			return;
		done++;

		specific = ">Tmid Thermal event with intelligent "
			   "throttling disabled";
		}
		break;
	}

	/* Form out message */
	snprintf(msg, sizeof(msg),
		 "Bank=%d RAS=%d CAS=%d FATAL Err=0x%x (%s)",
		 bank, ras, cas, allErrors, specific);

	/* Call the helper to output message */
	edac_mc_handle_error(HW_EVENT_ERR_FATAL, mci, 1, 0, 0, 0,
			     channel >> 1, channel & 1, rank,
			     rdwr ? "Write error" : "Read error",
			     msg);
}