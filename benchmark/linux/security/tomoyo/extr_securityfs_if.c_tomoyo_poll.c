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
typedef  int /*<<< orphan*/  poll_table ;
typedef  int /*<<< orphan*/  __poll_t ;

/* Variables and functions */
 int /*<<< orphan*/  tomoyo_poll_control (struct file*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static __poll_t tomoyo_poll(struct file *file, poll_table *wait)
{
	return tomoyo_poll_control(file, wait);
}