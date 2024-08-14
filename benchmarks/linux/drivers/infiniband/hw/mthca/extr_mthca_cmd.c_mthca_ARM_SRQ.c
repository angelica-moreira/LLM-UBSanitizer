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
 int /*<<< orphan*/  CMD_ARM_SRQ ; 
 int /*<<< orphan*/  CMD_TIME_CLASS_B ; 
 int mthca_cmd (struct mthca_dev*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int mthca_ARM_SRQ(struct mthca_dev *dev, int srq_num, int limit)
{
	return mthca_cmd(dev, limit, srq_num, 0, CMD_ARM_SRQ,
			 CMD_TIME_CLASS_B);
}