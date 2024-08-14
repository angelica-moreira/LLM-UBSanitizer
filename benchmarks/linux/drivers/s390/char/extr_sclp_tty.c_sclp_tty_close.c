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
struct tty_struct {int count; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sclp_port ; 
 int /*<<< orphan*/  tty_port_tty_set (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
sclp_tty_close(struct tty_struct *tty, struct file *filp)
{
	if (tty->count > 1)
		return;
	tty_port_tty_set(&sclp_port, NULL);
}