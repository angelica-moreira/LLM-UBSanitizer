#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct pci_dev {int dummy; } ;
struct ata_link {TYPE_2__* ap; } ;
struct TYPE_4__ {TYPE_1__* host; } ;
struct TYPE_3__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 unsigned int SCR_ERROR ; 
 unsigned int get_scr_cfg_addr (struct ata_link*,unsigned int) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,unsigned int,int /*<<< orphan*/ *) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32 sis_scr_cfg_read(struct ata_link *link,
			    unsigned int sc_reg, u32 *val)
{
	struct pci_dev *pdev = to_pci_dev(link->ap->host->dev);
	unsigned int cfg_addr = get_scr_cfg_addr(link, sc_reg);

	if (sc_reg == SCR_ERROR) /* doesn't exist in PCI cfg space */
		return -EINVAL;

	pci_read_config_dword(pdev, cfg_addr, val);
	return 0;
}