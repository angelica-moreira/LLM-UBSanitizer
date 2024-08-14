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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u16 ;
struct ib_device {int dummy; } ;

/* Variables and functions */

int siw_query_pkey(struct ib_device *base_dev, u8 port, u16 idx, u16 *pkey)
{
	/* Report the default pkey */
	*pkey = 0xffff;
	return 0;
}