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
struct niu {int /*<<< orphan*/  port; } ;

/* Variables and functions */
 int /*<<< orphan*/  ESR_RXTX_RESET_CTRL_H ; 
 int /*<<< orphan*/  ESR_RXTX_RESET_CTRL_L ; 
 int /*<<< orphan*/  NIU_ESR_DEV_ADDR ; 
 int mdio_read (struct niu*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int esr_read_reset(struct niu *np, u32 *val)
{
	int err;

	err = mdio_read(np, np->port, NIU_ESR_DEV_ADDR,
			ESR_RXTX_RESET_CTRL_L);
	if (err >= 0) {
		*val = (err & 0xffff);
		err = mdio_read(np, np->port, NIU_ESR_DEV_ADDR,
				ESR_RXTX_RESET_CTRL_H);
		if (err >= 0) {
			*val |= ((err & 0xffff) << 16);
			err = 0;
		}
	}
	return err;
}