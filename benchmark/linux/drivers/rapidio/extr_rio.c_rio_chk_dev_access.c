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
struct rio_dev {int /*<<< orphan*/  hopcount; int /*<<< orphan*/  destid; TYPE_1__* net; } ;
struct TYPE_2__ {int /*<<< orphan*/  hport; } ;

/* Variables and functions */
 int rio_mport_chk_dev_access (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rio_chk_dev_access(struct rio_dev *rdev)
{
	return rio_mport_chk_dev_access(rdev->net->hport,
					rdev->destid, rdev->hopcount);
}