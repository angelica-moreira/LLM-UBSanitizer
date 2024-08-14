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
struct mtd_info {int dummy; } ;
struct mtd_concat {int num_subdev; struct mtd_info** subdev; } ;

/* Variables and functions */
 struct mtd_concat* CONCAT (struct mtd_info*) ; 
 int mtd_suspend (struct mtd_info*) ; 

__attribute__((used)) static int concat_suspend(struct mtd_info *mtd)
{
	struct mtd_concat *concat = CONCAT(mtd);
	int i, rc = 0;

	for (i = 0; i < concat->num_subdev; i++) {
		struct mtd_info *subdev = concat->subdev[i];
		if ((rc = mtd_suspend(subdev)) < 0)
			return rc;
	}
	return rc;
}