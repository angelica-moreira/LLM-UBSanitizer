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
struct scm_device {int /*<<< orphan*/  dev; } ;
struct scm_blk_dev {int dummy; } ;

/* Variables and functions */
 struct scm_blk_dev* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct scm_blk_dev*) ; 
 int /*<<< orphan*/  scm_blk_dev_cleanup (struct scm_blk_dev*) ; 

__attribute__((used)) static int scm_remove(struct scm_device *scmdev)
{
	struct scm_blk_dev *bdev = dev_get_drvdata(&scmdev->dev);

	scm_blk_dev_cleanup(bdev);
	dev_set_drvdata(&scmdev->dev, NULL);
	kfree(bdev);

	return 0;
}