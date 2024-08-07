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
struct pcmcia_device {scalar_t__* prod_id; } ;

/* Variables and functions */
 scalar_t__ strstr (scalar_t__,char*) ; 

__attribute__((used)) static int
has_ce2_string(struct pcmcia_device * p_dev)
{
	if (p_dev->prod_id[2] && strstr(p_dev->prod_id[2], "CE2"))
		return 1;
	return 0;
}