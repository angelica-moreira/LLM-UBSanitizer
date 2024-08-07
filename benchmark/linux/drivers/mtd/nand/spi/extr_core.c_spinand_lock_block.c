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
struct spinand_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  REG_BLOCK_LOCK ; 
 int spinand_write_reg_op (struct spinand_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int spinand_lock_block(struct spinand_device *spinand, u8 lock)
{
	return spinand_write_reg_op(spinand, REG_BLOCK_LOCK, lock);
}