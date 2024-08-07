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
struct ubi_device {int /*<<< orphan*/  mtd; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  mtd_sync (int /*<<< orphan*/ ) ; 
 struct ubi_device* ubi_get_device (int) ; 
 int /*<<< orphan*/  ubi_put_device (struct ubi_device*) ; 

int ubi_sync(int ubi_num)
{
	struct ubi_device *ubi;

	ubi = ubi_get_device(ubi_num);
	if (!ubi)
		return -ENODEV;

	mtd_sync(ubi->mtd);
	ubi_put_device(ubi);
	return 0;
}