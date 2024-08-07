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
struct lpfc_vport {struct lpfc_hba* phba; } ;
struct lpfc_sli_ring {int /*<<< orphan*/  txcmplq_max; } ;
struct lpfc_hba {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
struct Scsi_Host {scalar_t__ hostdata; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 struct Scsi_Host* class_to_shost (struct device*) ; 
 struct lpfc_sli_ring* lpfc_phba_elsring (struct lpfc_hba*) ; 
 int /*<<< orphan*/  scnprintf (char*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t
lpfc_txcmplq_hw_show(struct device *dev, struct device_attribute *attr,
 char *buf)
{
	struct Scsi_Host  *shost = class_to_shost(dev);
	struct lpfc_hba   *phba = ((struct lpfc_vport *) shost->hostdata)->phba;
	struct lpfc_sli_ring *pring = lpfc_phba_elsring(phba);

	return scnprintf(buf, PAGE_SIZE, "%d\n",
			pring ? pring->txcmplq_max : 0);
}