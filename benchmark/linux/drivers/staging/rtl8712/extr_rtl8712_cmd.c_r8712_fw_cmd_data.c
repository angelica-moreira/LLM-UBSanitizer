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
typedef  scalar_t__ u8 ;
typedef  int /*<<< orphan*/  u32 ;
struct _adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IOCMD_DATA_REG ; 
 int /*<<< orphan*/  r8712_read32 (struct _adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r8712_write32 (struct _adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void r8712_fw_cmd_data(struct _adapter *pAdapter, u32 *value, u8 flag)
{
	if (flag == 0)	/* set */
		r8712_write32(pAdapter, IOCMD_DATA_REG, *value);
	else		/* query */
		*value = r8712_read32(pAdapter, IOCMD_DATA_REG);
}