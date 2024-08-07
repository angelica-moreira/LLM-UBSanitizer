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
struct niu {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MIF_FRAME_OUTPUT ; 
 int /*<<< orphan*/  MII_WRITE_OP (int,int,int) ; 
 int mdio_wait (struct niu*) ; 
 int /*<<< orphan*/  nw64 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mii_write(struct niu *np, int port, int reg, int data)
{
	int err;

	nw64(MIF_FRAME_OUTPUT, MII_WRITE_OP(port, reg, data));
	err = mdio_wait(np);
	if (err < 0)
		return err;

	return 0;
}