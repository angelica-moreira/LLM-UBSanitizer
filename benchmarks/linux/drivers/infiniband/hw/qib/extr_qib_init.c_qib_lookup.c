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
struct qib_devdata {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  qib_dev_table ; 
 struct qib_devdata* xa_load (int /*<<< orphan*/ *,int) ; 

struct qib_devdata *qib_lookup(int unit)
{
	return xa_load(&qib_dev_table, unit);
}