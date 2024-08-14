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
struct t3cdev {int /*<<< orphan*/  ofld_dev_list; } ;

/* Variables and functions */
 int /*<<< orphan*/  cxgb3_db_lock ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void unregister_tdev(struct t3cdev *tdev)
{
	mutex_lock(&cxgb3_db_lock);
	list_del(&tdev->ofld_dev_list);
	mutex_unlock(&cxgb3_db_lock);
}