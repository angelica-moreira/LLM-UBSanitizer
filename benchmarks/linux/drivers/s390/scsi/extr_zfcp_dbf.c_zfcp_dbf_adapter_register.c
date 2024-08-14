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
struct zfcp_dbf_scsi {int dummy; } ;
struct zfcp_dbf_san {int dummy; } ;
struct zfcp_dbf_rec {int dummy; } ;
struct zfcp_dbf_pay {int dummy; } ;
struct zfcp_dbf_hba {int dummy; } ;
struct zfcp_dbf {void* scsi; void* san; void* pay; void* hba; void* rec; int /*<<< orphan*/  rec_lock; int /*<<< orphan*/  scsi_lock; int /*<<< orphan*/  san_lock; int /*<<< orphan*/  hba_lock; int /*<<< orphan*/  pay_lock; } ;
struct zfcp_adapter {struct zfcp_dbf* dbf; TYPE_1__* ccw_device; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int DEBUG_MAX_NAME_LEN ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int dbfsize ; 
 char* dev_name (int /*<<< orphan*/ *) ; 
 struct zfcp_dbf* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*) ; 
 void* zfcp_dbf_reg (char*,int,int) ; 
 int /*<<< orphan*/  zfcp_dbf_unregister (struct zfcp_dbf*) ; 

int zfcp_dbf_adapter_register(struct zfcp_adapter *adapter)
{
	char name[DEBUG_MAX_NAME_LEN];
	struct zfcp_dbf *dbf;

	dbf = kzalloc(sizeof(struct zfcp_dbf), GFP_KERNEL);
	if (!dbf)
		return -ENOMEM;

	spin_lock_init(&dbf->pay_lock);
	spin_lock_init(&dbf->hba_lock);
	spin_lock_init(&dbf->san_lock);
	spin_lock_init(&dbf->scsi_lock);
	spin_lock_init(&dbf->rec_lock);

	/* debug feature area which records recovery activity */
	sprintf(name, "zfcp_%s_rec", dev_name(&adapter->ccw_device->dev));
	dbf->rec = zfcp_dbf_reg(name, dbfsize, sizeof(struct zfcp_dbf_rec));
	if (!dbf->rec)
		goto err_out;

	/* debug feature area which records HBA (FSF and QDIO) conditions */
	sprintf(name, "zfcp_%s_hba", dev_name(&adapter->ccw_device->dev));
	dbf->hba = zfcp_dbf_reg(name, dbfsize, sizeof(struct zfcp_dbf_hba));
	if (!dbf->hba)
		goto err_out;

	/* debug feature area which records payload info */
	sprintf(name, "zfcp_%s_pay", dev_name(&adapter->ccw_device->dev));
	dbf->pay = zfcp_dbf_reg(name, dbfsize * 2, sizeof(struct zfcp_dbf_pay));
	if (!dbf->pay)
		goto err_out;

	/* debug feature area which records SAN command failures and recovery */
	sprintf(name, "zfcp_%s_san", dev_name(&adapter->ccw_device->dev));
	dbf->san = zfcp_dbf_reg(name, dbfsize, sizeof(struct zfcp_dbf_san));
	if (!dbf->san)
		goto err_out;

	/* debug feature area which records SCSI command failures and recovery */
	sprintf(name, "zfcp_%s_scsi", dev_name(&adapter->ccw_device->dev));
	dbf->scsi = zfcp_dbf_reg(name, dbfsize, sizeof(struct zfcp_dbf_scsi));
	if (!dbf->scsi)
		goto err_out;

	adapter->dbf = dbf;

	return 0;
err_out:
	zfcp_dbf_unregister(dbf);
	return -ENOMEM;
}