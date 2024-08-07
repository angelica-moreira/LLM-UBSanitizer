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
struct mtd_blktrans_dev {int /*<<< orphan*/  devnum; } ;
struct INFTLrecord {int /*<<< orphan*/  VUtable; int /*<<< orphan*/  PUtable; } ;

/* Variables and functions */
 int /*<<< orphan*/  del_mtd_blktrans_dev (struct mtd_blktrans_dev*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void inftl_remove_dev(struct mtd_blktrans_dev *dev)
{
	struct INFTLrecord *inftl = (void *)dev;

	pr_debug("INFTL: remove_dev (i=%d)\n", dev->devnum);

	del_mtd_blktrans_dev(dev);

	kfree(inftl->PUtable);
	kfree(inftl->VUtable);
}