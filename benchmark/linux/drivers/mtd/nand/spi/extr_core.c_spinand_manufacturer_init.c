#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct spinand_device {TYPE_2__* manufacturer; } ;
struct TYPE_4__ {TYPE_1__* ops; } ;
struct TYPE_3__ {int (* init ) (struct spinand_device*) ;} ;

/* Variables and functions */
 int stub1 (struct spinand_device*) ; 

__attribute__((used)) static int spinand_manufacturer_init(struct spinand_device *spinand)
{
	if (spinand->manufacturer->ops->init)
		return spinand->manufacturer->ops->init(spinand);

	return 0;
}