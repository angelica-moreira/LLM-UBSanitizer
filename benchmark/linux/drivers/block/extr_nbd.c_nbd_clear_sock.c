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
struct nbd_device {int /*<<< orphan*/ * task_setup; } ;

/* Variables and functions */
 int /*<<< orphan*/  nbd_clear_que (struct nbd_device*) ; 
 int /*<<< orphan*/  sock_shutdown (struct nbd_device*) ; 

__attribute__((used)) static void nbd_clear_sock(struct nbd_device *nbd)
{
	sock_shutdown(nbd);
	nbd_clear_que(nbd);
	nbd->task_setup = NULL;
}