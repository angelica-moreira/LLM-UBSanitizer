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
struct sigevent {scalar_t__ sigev_signo; } ;
struct TYPE_2__ {int /*<<< orphan*/  mqdes; scalar_t__ sigev_signo; } ;
struct audit_context {int /*<<< orphan*/  type; TYPE_1__ mq_notify; } ;
typedef  int /*<<< orphan*/  mqd_t ;

/* Variables and functions */
 int /*<<< orphan*/  AUDIT_MQ_NOTIFY ; 
 struct audit_context* audit_context () ; 

void __audit_mq_notify(mqd_t mqdes, const struct sigevent *notification)
{
	struct audit_context *context = audit_context();

	if (notification)
		context->mq_notify.sigev_signo = notification->sigev_signo;
	else
		context->mq_notify.sigev_signo = 0;

	context->mq_notify.mqdes = mqdes;
	context->type = AUDIT_MQ_NOTIFY;
}