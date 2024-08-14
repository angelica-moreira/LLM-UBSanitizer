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
struct socket {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AA_MAY_SHUTDOWN ; 
 int /*<<< orphan*/  OP_SHUTDOWN ; 
 int aa_sock_perm (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct socket*) ; 

__attribute__((used)) static int apparmor_socket_shutdown(struct socket *sock, int how)
{
	return aa_sock_perm(OP_SHUTDOWN, AA_MAY_SHUTDOWN, sock);
}