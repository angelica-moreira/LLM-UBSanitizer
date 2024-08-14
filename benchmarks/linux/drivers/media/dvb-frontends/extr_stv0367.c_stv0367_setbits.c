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
typedef  int u8 ;
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  extract_mask_pos (int /*<<< orphan*/ ,int*,int*) ; 

__attribute__((used)) static void stv0367_setbits(u8 *reg, u32 label, u8 val)
{
	u8 mask, pos;

	extract_mask_pos(label, &mask, &pos);

	val = mask & (val << pos);

	(*reg) = ((*reg) & (~mask)) | val;
}