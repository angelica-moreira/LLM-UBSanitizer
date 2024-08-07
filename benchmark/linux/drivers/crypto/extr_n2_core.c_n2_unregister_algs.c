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

/* Variables and functions */
 int /*<<< orphan*/  __n2_unregister_algs () ; 
 int /*<<< orphan*/  algs_registered ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spu_lock ; 

__attribute__((used)) static void n2_unregister_algs(void)
{
	mutex_lock(&spu_lock);
	if (!--algs_registered)
		__n2_unregister_algs();
	mutex_unlock(&spu_lock);
}