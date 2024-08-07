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
struct netxen_adapter {TYPE_1__* pdev; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EIO ; 
 long NETXEN_MAX_ROM_WAIT_USEC ; 
 int /*<<< orphan*/  NETXEN_ROMUSB_GLB_STATUS ; 
 long NXRD32 (struct netxen_adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int netxen_wait_rom_done(struct netxen_adapter *adapter)
{
	long timeout = 0;
	long done = 0;

	cond_resched();

	while (done == 0) {
		done = NXRD32(adapter, NETXEN_ROMUSB_GLB_STATUS);
		done &= 2;
		if (++timeout >= NETXEN_MAX_ROM_WAIT_USEC) {
			dev_err(&adapter->pdev->dev,
				"Timeout reached  waiting for rom done");
			return -EIO;
		}
		udelay(1);
	}
	return 0;
}