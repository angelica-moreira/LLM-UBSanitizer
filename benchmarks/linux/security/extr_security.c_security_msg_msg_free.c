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
struct msg_msg {int /*<<< orphan*/ * security; } ;

/* Variables and functions */
 int /*<<< orphan*/  call_void_hook (int /*<<< orphan*/ ,struct msg_msg*) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msg_msg_free_security ; 

void security_msg_msg_free(struct msg_msg *msg)
{
	call_void_hook(msg_msg_free_security, msg);
	kfree(msg->security);
	msg->security = NULL;
}