#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct device {int dummy; } ;
struct TYPE_2__ {int is_thunderbolt; } ;

/* Variables and functions */
 TYPE_1__* to_pci_dev (struct device*) ; 

__attribute__((used)) static int is_thunderbolt(struct device *dev, void *data)
{
	return to_pci_dev(dev)->is_thunderbolt;
}