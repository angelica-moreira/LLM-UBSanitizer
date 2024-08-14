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
struct pqi_scsi_dev {int /*<<< orphan*/  scsi3addr; int /*<<< orphan*/  is_physical_device; } ;

/* Variables and functions */
 int /*<<< orphan*/  pqi_skip_device (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool pqi_expose_device(struct pqi_scsi_dev *device)
{
	return !device->is_physical_device ||
		!pqi_skip_device(device->scsi3addr);
}