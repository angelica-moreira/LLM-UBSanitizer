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
 int /*<<< orphan*/  OLPC_GPIO_MIC_AC ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 

void olpc_quirks_cleanup(void)
{
	gpio_free(OLPC_GPIO_MIC_AC);
}