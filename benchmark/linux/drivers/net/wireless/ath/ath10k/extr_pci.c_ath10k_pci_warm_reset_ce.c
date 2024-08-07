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
struct ath10k {int dummy; } ;

/* Variables and functions */
 scalar_t__ RTC_SOC_BASE_ADDRESS ; 
 scalar_t__ SOC_RESET_CONTROL_ADDRESS ; 
 int SOC_RESET_CONTROL_CE_RST_MASK ; 
 int ath10k_pci_read32 (struct ath10k*,scalar_t__) ; 
 int /*<<< orphan*/  ath10k_pci_write32 (struct ath10k*,scalar_t__,int) ; 
 int /*<<< orphan*/  msleep (int) ; 

__attribute__((used)) static void ath10k_pci_warm_reset_ce(struct ath10k *ar)
{
	u32 val;

	val = ath10k_pci_read32(ar, RTC_SOC_BASE_ADDRESS +
				SOC_RESET_CONTROL_ADDRESS);

	ath10k_pci_write32(ar, RTC_SOC_BASE_ADDRESS + SOC_RESET_CONTROL_ADDRESS,
			   val | SOC_RESET_CONTROL_CE_RST_MASK);
	msleep(10);
	ath10k_pci_write32(ar, RTC_SOC_BASE_ADDRESS + SOC_RESET_CONTROL_ADDRESS,
			   val & ~SOC_RESET_CONTROL_CE_RST_MASK);
}