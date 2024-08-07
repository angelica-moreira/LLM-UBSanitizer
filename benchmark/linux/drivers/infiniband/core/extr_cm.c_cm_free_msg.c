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
struct ib_mad_send_buf {scalar_t__* context; scalar_t__ ah; } ;

/* Variables and functions */
 int /*<<< orphan*/  cm_deref_id (scalar_t__) ; 
 int /*<<< orphan*/  ib_free_send_mad (struct ib_mad_send_buf*) ; 
 int /*<<< orphan*/  rdma_destroy_ah (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void cm_free_msg(struct ib_mad_send_buf *msg)
{
	if (msg->ah)
		rdma_destroy_ah(msg->ah, 0);
	if (msg->context[0])
		cm_deref_id(msg->context[0]);
	ib_free_send_mad(msg);
}