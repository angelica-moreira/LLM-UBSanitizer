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

/* Variables and functions */
 int /*<<< orphan*/  PIDTYPE_TGID ; 
 int /*<<< orphan*/  f_modown (struct file*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

void f_delown(struct file *filp)
{
	f_modown(filp, NULL, PIDTYPE_TGID, 1);
}