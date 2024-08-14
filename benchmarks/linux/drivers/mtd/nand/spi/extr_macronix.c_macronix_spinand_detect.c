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
typedef  scalar_t__ u8 ;
struct TYPE_2__ {scalar_t__* data; } ;
struct spinand_device {TYPE_1__ id; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 scalar_t__ SPINAND_MFR_MACRONIX ; 
 int /*<<< orphan*/  macronix_spinand_table ; 
 int spinand_match_and_init (struct spinand_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int macronix_spinand_detect(struct spinand_device *spinand)
{
	u8 *id = spinand->id.data;
	int ret;

	/*
	 * Macronix SPI NAND read ID needs a dummy byte, so the first byte in
	 * raw_id is garbage.
	 */
	if (id[1] != SPINAND_MFR_MACRONIX)
		return 0;

	ret = spinand_match_and_init(spinand, macronix_spinand_table,
				     ARRAY_SIZE(macronix_spinand_table),
				     id[2]);
	if (ret)
		return ret;

	return 1;
}