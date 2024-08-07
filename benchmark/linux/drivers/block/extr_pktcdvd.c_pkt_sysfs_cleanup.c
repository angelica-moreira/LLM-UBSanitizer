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
 int /*<<< orphan*/  class_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * class_pktcdvd ; 

__attribute__((used)) static void pkt_sysfs_cleanup(void)
{
	if (class_pktcdvd)
		class_destroy(class_pktcdvd);
	class_pktcdvd = NULL;
}