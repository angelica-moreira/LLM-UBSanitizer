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
struct mthca_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_NOP ; 
 int /*<<< orphan*/  msecs_to_jiffies (int) ; 
 int mthca_cmd (struct mthca_dev*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int mthca_NOP(struct mthca_dev *dev)
{
	return mthca_cmd(dev, 0, 0x1f, 0, CMD_NOP, msecs_to_jiffies(100));
}