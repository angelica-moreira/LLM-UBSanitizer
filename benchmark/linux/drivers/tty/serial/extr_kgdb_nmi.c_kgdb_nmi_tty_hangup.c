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
struct tty_struct {struct kgdb_nmi_tty_priv* driver_data; } ;
struct kgdb_nmi_tty_priv {int /*<<< orphan*/  port; } ;

/* Variables and functions */
 int /*<<< orphan*/  tty_port_hangup (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void kgdb_nmi_tty_hangup(struct tty_struct *tty)
{
	struct kgdb_nmi_tty_priv *priv = tty->driver_data;

	tty_port_hangup(&priv->port);
}