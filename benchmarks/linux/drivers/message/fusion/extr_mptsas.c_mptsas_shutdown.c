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
struct pci_dev {int dummy; } ;
typedef  int /*<<< orphan*/  MPT_ADAPTER ;

/* Variables and functions */
 int /*<<< orphan*/  mptsas_cleanup_fw_event_q (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mptsas_fw_event_off (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pci_get_drvdata (struct pci_dev*) ; 

__attribute__((used)) static void
mptsas_shutdown(struct pci_dev *pdev)
{
	MPT_ADAPTER *ioc = pci_get_drvdata(pdev);

	mptsas_fw_event_off(ioc);
	mptsas_cleanup_fw_event_q(ioc);
}