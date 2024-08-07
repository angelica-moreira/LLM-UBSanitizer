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
struct dm_target {int num_secure_erase_bios; } ;

/* Variables and functions */

__attribute__((used)) static unsigned get_num_secure_erase_bios(struct dm_target *ti)
{
	return ti->num_secure_erase_bios;
}