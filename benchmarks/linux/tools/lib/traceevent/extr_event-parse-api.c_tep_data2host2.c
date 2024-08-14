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
struct tep_handle {scalar_t__ host_bigendian; scalar_t__ file_bigendian; } ;

/* Variables and functions */

unsigned short tep_data2host2(struct tep_handle *tep, unsigned short data)
{
	unsigned short swap;

	if (!tep || tep->host_bigendian == tep->file_bigendian)
		return data;

	swap = ((data & 0xffULL) << 8) |
		((data & (0xffULL << 8)) >> 8);

	return swap;
}