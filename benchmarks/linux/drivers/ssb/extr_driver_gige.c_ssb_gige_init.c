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
 int ssb_driver_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ssb_gige_driver ; 

int ssb_gige_init(void)
{
	return ssb_driver_register(&ssb_gige_driver);
}