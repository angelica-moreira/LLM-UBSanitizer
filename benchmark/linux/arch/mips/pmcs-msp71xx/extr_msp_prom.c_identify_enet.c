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
 int /*<<< orphan*/  ENET_KEY ; 
 char identify_enetfeature (int /*<<< orphan*/ ,unsigned long) ; 

char identify_enet(unsigned long interface_num)
{
	return identify_enetfeature(ENET_KEY, interface_num);
}