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
struct file {int dummy; } ;
typedef  int /*<<< orphan*/  fl_owner_t ;

/* Variables and functions */
 int /*<<< orphan*/  ps3flash_dev ; 
 int ps3flash_writeback (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ps3flash_flush(struct file *file, fl_owner_t id)
{
	return ps3flash_writeback(ps3flash_dev);
}