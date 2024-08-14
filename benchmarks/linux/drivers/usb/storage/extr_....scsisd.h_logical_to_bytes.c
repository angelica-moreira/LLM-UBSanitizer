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
struct scsi_device {unsigned int sector_size; } ;
typedef  unsigned int sector_t ;

/* Variables and functions */

__attribute__((used)) static inline unsigned int logical_to_bytes(struct scsi_device *sdev, sector_t blocks)
{
	return blocks * sdev->sector_size;
}