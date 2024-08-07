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
typedef  int /*<<< orphan*/  dev_t ;

/* Variables and functions */
 int /*<<< orphan*/  MINOR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fsi_minor_ida ; 
 int /*<<< orphan*/  ida_simple_remove (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void fsi_free_minor(dev_t dev)
{
	ida_simple_remove(&fsi_minor_ida, MINOR(dev));
}