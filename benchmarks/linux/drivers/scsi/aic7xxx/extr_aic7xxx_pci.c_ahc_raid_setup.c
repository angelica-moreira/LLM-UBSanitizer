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
struct ahc_softc {int dummy; } ;

/* Variables and functions */
 int ENXIO ; 
 int /*<<< orphan*/  printk (char*) ; 

__attribute__((used)) static int
ahc_raid_setup(struct ahc_softc *ahc)
{
	printk("RAID functionality unsupported\n");
	return (ENXIO);
}