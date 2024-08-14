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
struct dasd_device {int /*<<< orphan*/  opm; } ;
typedef  int /*<<< orphan*/  __u8 ;

/* Variables and functions */

__attribute__((used)) static inline __u8 dasd_path_get_opm(struct dasd_device *device)
{
	return device->opm;
}