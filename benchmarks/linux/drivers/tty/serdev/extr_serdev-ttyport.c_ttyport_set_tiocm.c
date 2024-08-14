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
struct tty_struct {TYPE_1__* ops; } ;
struct serport {struct tty_struct* tty; } ;
struct serdev_controller {int dummy; } ;
struct TYPE_2__ {int (* tiocmset ) (struct tty_struct*,unsigned int,unsigned int) ;} ;

/* Variables and functions */
 int ENOTSUPP ; 
 struct serport* serdev_controller_get_drvdata (struct serdev_controller*) ; 
 int stub1 (struct tty_struct*,unsigned int,unsigned int) ; 

__attribute__((used)) static int ttyport_set_tiocm(struct serdev_controller *ctrl, unsigned int set, unsigned int clear)
{
	struct serport *serport = serdev_controller_get_drvdata(ctrl);
	struct tty_struct *tty = serport->tty;

	if (!tty->ops->tiocmset)
		return -ENOTSUPP;

	return tty->ops->tiocmset(tty, set, clear);
}