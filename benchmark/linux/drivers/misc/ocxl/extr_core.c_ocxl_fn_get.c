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
struct ocxl_fn {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/ * get_device (int /*<<< orphan*/ *) ; 

__attribute__((used)) static struct ocxl_fn *ocxl_fn_get(struct ocxl_fn *fn)
{
	return (get_device(&fn->dev) == NULL) ? NULL : fn;
}