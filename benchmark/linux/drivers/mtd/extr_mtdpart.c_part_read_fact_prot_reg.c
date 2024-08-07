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
typedef  int /*<<< orphan*/  u_char ;
struct mtd_part {TYPE_1__* parent; } ;
struct mtd_info {int dummy; } ;
typedef  int /*<<< orphan*/  loff_t ;
struct TYPE_2__ {int (* _read_fact_prot_reg ) (TYPE_1__*,int /*<<< orphan*/ ,size_t,size_t*,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 struct mtd_part* mtd_to_part (struct mtd_info*) ; 
 int stub1 (TYPE_1__*,int /*<<< orphan*/ ,size_t,size_t*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int part_read_fact_prot_reg(struct mtd_info *mtd, loff_t from,
		size_t len, size_t *retlen, u_char *buf)
{
	struct mtd_part *part = mtd_to_part(mtd);
	return part->parent->_read_fact_prot_reg(part->parent, from, len,
						 retlen, buf);
}