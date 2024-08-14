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
struct siox_master {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct siox_master*) ; 
 struct siox_master* to_siox_master (struct device*) ; 

__attribute__((used)) static void siox_master_release(struct device *dev)
{
	struct siox_master *smaster = to_siox_master(dev);

	kfree(smaster);
}