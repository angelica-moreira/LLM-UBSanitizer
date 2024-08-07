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
struct blk_integrity {int flags; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int BLK_INTEGRITY_DEVICE_CAPABLE ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static ssize_t integrity_device_show(struct blk_integrity *bi, char *page)
{
	return sprintf(page, "%u\n",
		       (bi->flags & BLK_INTEGRITY_DEVICE_CAPABLE) != 0);
}