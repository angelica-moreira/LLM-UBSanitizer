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
struct iscsi_cls_conn {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  iscsi_conn_teardown (struct iscsi_cls_conn*) ; 

void iscsi_tcp_conn_teardown(struct iscsi_cls_conn *cls_conn)
{
	iscsi_conn_teardown(cls_conn);
}