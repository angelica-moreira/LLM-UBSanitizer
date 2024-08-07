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
struct md_rdev {int /*<<< orphan*/  badblocks; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  badblocks_show (int /*<<< orphan*/ *,char*,int) ; 

__attribute__((used)) static ssize_t ubb_show(struct md_rdev *rdev, char *page)
{
	return badblocks_show(&rdev->badblocks, page, 1);
}