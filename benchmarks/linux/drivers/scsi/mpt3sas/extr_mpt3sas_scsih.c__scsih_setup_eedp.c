#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct scsi_cmnd {TYPE_3__* device; int /*<<< orphan*/  request; } ;
struct MPT3SAS_ADAPTER {scalar_t__ is_gen35_ioc; } ;
struct TYPE_6__ {int /*<<< orphan*/  PrimaryReferenceTag; } ;
struct TYPE_7__ {TYPE_1__ EEDP32; } ;
struct TYPE_9__ {void* EEDPFlags; void* EEDPBlockSize; TYPE_2__ CDB; } ;
struct TYPE_8__ {int sector_size; } ;
typedef  TYPE_4__ Mpi25SCSIIORequest_t ;

/* Variables and functions */
 int MPI25_SCSIIO_EEDPFLAGS_APPTAG_DISABLE_MODE ; 
 int MPI2_SCSIIO_EEDPFLAGS_CHECK_GUARD ; 
 int MPI2_SCSIIO_EEDPFLAGS_CHECK_REFTAG ; 
 int MPI2_SCSIIO_EEDPFLAGS_CHECK_REMOVE_OP ; 
 int MPI2_SCSIIO_EEDPFLAGS_INC_PRI_REFTAG ; 
 int MPI2_SCSIIO_EEDPFLAGS_INSERT_OP ; 
 unsigned char SCSI_PROT_DIF_TYPE0 ; 
#define  SCSI_PROT_DIF_TYPE1 130 
#define  SCSI_PROT_DIF_TYPE2 129 
#define  SCSI_PROT_DIF_TYPE3 128 
 unsigned char SCSI_PROT_NORMAL ; 
 unsigned char SCSI_PROT_READ_STRIP ; 
 unsigned char SCSI_PROT_WRITE_INSERT ; 
 int /*<<< orphan*/  cpu_to_be32 (int /*<<< orphan*/ ) ; 
 void* cpu_to_le16 (int) ; 
 unsigned char scsi_get_prot_op (struct scsi_cmnd*) ; 
 unsigned char scsi_get_prot_type (struct scsi_cmnd*) ; 
 int /*<<< orphan*/  t10_pi_ref_tag (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
_scsih_setup_eedp(struct MPT3SAS_ADAPTER *ioc, struct scsi_cmnd *scmd,
	Mpi25SCSIIORequest_t *mpi_request)
{
	u16 eedp_flags;
	unsigned char prot_op = scsi_get_prot_op(scmd);
	unsigned char prot_type = scsi_get_prot_type(scmd);
	Mpi25SCSIIORequest_t *mpi_request_3v =
	   (Mpi25SCSIIORequest_t *)mpi_request;

	if (prot_type == SCSI_PROT_DIF_TYPE0 || prot_op == SCSI_PROT_NORMAL)
		return;

	if (prot_op ==  SCSI_PROT_READ_STRIP)
		eedp_flags = MPI2_SCSIIO_EEDPFLAGS_CHECK_REMOVE_OP;
	else if (prot_op ==  SCSI_PROT_WRITE_INSERT)
		eedp_flags = MPI2_SCSIIO_EEDPFLAGS_INSERT_OP;
	else
		return;

	switch (prot_type) {
	case SCSI_PROT_DIF_TYPE1:
	case SCSI_PROT_DIF_TYPE2:

		/*
		* enable ref/guard checking
		* auto increment ref tag
		*/
		eedp_flags |= MPI2_SCSIIO_EEDPFLAGS_INC_PRI_REFTAG |
		    MPI2_SCSIIO_EEDPFLAGS_CHECK_REFTAG |
		    MPI2_SCSIIO_EEDPFLAGS_CHECK_GUARD;
		mpi_request->CDB.EEDP32.PrimaryReferenceTag =
		    cpu_to_be32(t10_pi_ref_tag(scmd->request));
		break;

	case SCSI_PROT_DIF_TYPE3:

		/*
		* enable guard checking
		*/
		eedp_flags |= MPI2_SCSIIO_EEDPFLAGS_CHECK_GUARD;

		break;
	}

	mpi_request_3v->EEDPBlockSize =
	    cpu_to_le16(scmd->device->sector_size);

	if (ioc->is_gen35_ioc)
		eedp_flags |= MPI25_SCSIIO_EEDPFLAGS_APPTAG_DISABLE_MODE;
	mpi_request->EEDPFlags = cpu_to_le16(eedp_flags);
}