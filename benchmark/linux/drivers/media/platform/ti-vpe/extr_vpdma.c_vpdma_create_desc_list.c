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
struct TYPE_2__ {int /*<<< orphan*/  addr; } ;
struct vpdma_desc_list {int type; TYPE_1__ buf; int /*<<< orphan*/  next; } ;

/* Variables and functions */
 int vpdma_alloc_desc_buf (TYPE_1__*,size_t) ; 

int vpdma_create_desc_list(struct vpdma_desc_list *list, size_t size, int type)
{
	int r;

	r = vpdma_alloc_desc_buf(&list->buf, size);
	if (r)
		return r;

	list->next = list->buf.addr;

	list->type = type;

	return 0;
}