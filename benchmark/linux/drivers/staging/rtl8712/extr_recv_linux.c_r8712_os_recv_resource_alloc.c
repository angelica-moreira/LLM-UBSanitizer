#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/ * pkt; int /*<<< orphan*/ * pkt_newalloc; } ;
struct TYPE_4__ {TYPE_1__ hdr; } ;
union recv_frame {TYPE_2__ u; } ;
struct _adapter {int dummy; } ;

/* Variables and functions */

void r8712_os_recv_resource_alloc(struct _adapter *padapter,
				  union recv_frame *precvframe)
{
	precvframe->u.hdr.pkt_newalloc = NULL;
	precvframe->u.hdr.pkt = NULL;
}