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
struct qed_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DBG_FEATURE_REG_FIFO ; 
 int qed_dbg_feature_size (struct qed_dev*,int /*<<< orphan*/ ) ; 

int qed_dbg_reg_fifo_size(struct qed_dev *cdev)
{
	return qed_dbg_feature_size(cdev, DBG_FEATURE_REG_FIFO);
}