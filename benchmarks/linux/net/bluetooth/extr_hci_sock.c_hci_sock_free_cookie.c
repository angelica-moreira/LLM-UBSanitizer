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
struct sock {int dummy; } ;
struct TYPE_2__ {int cookie; } ;

/* Variables and functions */
 TYPE_1__* hci_pi (struct sock*) ; 
 int /*<<< orphan*/  ida_simple_remove (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sock_cookie_ida ; 

__attribute__((used)) static void hci_sock_free_cookie(struct sock *sk)
{
	int id = hci_pi(sk)->cookie;

	if (id) {
		hci_pi(sk)->cookie = 0xffffffff;
		ida_simple_remove(&sock_cookie_ida, id);
	}
}