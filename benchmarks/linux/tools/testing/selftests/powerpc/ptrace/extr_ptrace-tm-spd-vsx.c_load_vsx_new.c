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
 int /*<<< orphan*/  fp_load_new ; 
 int /*<<< orphan*/  loadvsx (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) void load_vsx_new(void)
{
	loadvsx(fp_load_new, 0);
}