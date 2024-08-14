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
struct mthca_mailbox {int /*<<< orphan*/  dma; } ;
struct mthca_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_TIME_CLASS_A ; 
 int /*<<< orphan*/  CMD_WRITE_MGM ; 
 int mthca_cmd (struct mthca_dev*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int mthca_WRITE_MGM(struct mthca_dev *dev, int index,
		    struct mthca_mailbox *mailbox)
{
	return mthca_cmd(dev, mailbox->dma, index, 0, CMD_WRITE_MGM,
			 CMD_TIME_CLASS_A);
}