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
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * raw_capacity ; 

__attribute__((used)) static int free_raw_capacity(void)
{
	kfree(raw_capacity);
	raw_capacity = NULL;

	return 0;
}