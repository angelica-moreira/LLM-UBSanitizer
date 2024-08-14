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
struct qedi_ctx {int /*<<< orphan*/  lcl_port_tbl; int /*<<< orphan*/ * ep_tbl; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  qedi_free_id_tbl (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void qedi_cm_free_mem(struct qedi_ctx *qedi)
{
	kfree(qedi->ep_tbl);
	qedi->ep_tbl = NULL;
	qedi_free_id_tbl(&qedi->lcl_port_tbl);
}