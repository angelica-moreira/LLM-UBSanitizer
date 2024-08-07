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
struct work_struct {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  brcmf_pcie_register () ; 
 int /*<<< orphan*/  brcmf_sdio_register () ; 
 int /*<<< orphan*/  brcmf_usb_register () ; 

__attribute__((used)) static void brcmf_driver_register(struct work_struct *work)
{
#ifdef CONFIG_BRCMFMAC_SDIO
	brcmf_sdio_register();
#endif
#ifdef CONFIG_BRCMFMAC_USB
	brcmf_usb_register();
#endif
#ifdef CONFIG_BRCMFMAC_PCIE
	brcmf_pcie_register();
#endif
}