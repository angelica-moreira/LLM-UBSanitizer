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
struct tty_struct {scalar_t__ magic; int /*<<< orphan*/  legacy_mutex; } ;

/* Variables and functions */
 scalar_t__ TTY_MAGIC ; 
 scalar_t__ WARN (int,char*,struct tty_struct*) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tty_kref_put (struct tty_struct*) ; 

void tty_unlock(struct tty_struct *tty)
{
	if (WARN(tty->magic != TTY_MAGIC, "U Bad %p\n", tty))
		return;
	mutex_unlock(&tty->legacy_mutex);
	tty_kref_put(tty);
}