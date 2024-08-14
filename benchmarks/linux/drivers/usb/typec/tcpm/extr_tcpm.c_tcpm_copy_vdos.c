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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 unsigned int VDO_MAX_OBJECTS ; 

__attribute__((used)) static int tcpm_copy_vdos(u32 *dest_vdo, const u32 *src_vdo,
			  unsigned int nr_vdo)
{
	unsigned int i;

	if (nr_vdo > VDO_MAX_OBJECTS)
		nr_vdo = VDO_MAX_OBJECTS;

	for (i = 0; i < nr_vdo; i++)
		dest_vdo[i] = src_vdo[i];

	return nr_vdo;
}