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
struct rtsx_pcr {int host_cmds_addr; int ci; } ;

/* Variables and functions */
 int /*<<< orphan*/  RTSX_HCBAR ; 
 int /*<<< orphan*/  RTSX_HCBCTLR ; 
 int /*<<< orphan*/  rtsx_pci_writel (struct rtsx_pcr*,int /*<<< orphan*/ ,int) ; 

void rtsx_pci_send_cmd_no_wait(struct rtsx_pcr *pcr)
{
	u32 val = 1 << 31;

	rtsx_pci_writel(pcr, RTSX_HCBAR, pcr->host_cmds_addr);

	val |= (u32)(pcr->ci * 4) & 0x00FFFFFF;
	/* Hardware Auto Response */
	val |= 0x40000000;
	rtsx_pci_writel(pcr, RTSX_HCBCTLR, val);
}