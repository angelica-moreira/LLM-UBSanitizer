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
typedef  scalar_t__ uint32_t ;
struct TYPE_2__ {int /*<<< orphan*/ * ops; } ;
struct hvc_struct {scalar_t__ vtermno; int data; int outbuf_size; char* outbuf; int index; int /*<<< orphan*/  next; struct hv_ops const* ops; int /*<<< orphan*/  lock; int /*<<< orphan*/  tty_resize; TYPE_1__ port; } ;
struct hv_ops {int dummy; } ;

/* Variables and functions */
 size_t ALIGN (int,int) ; 
 int ENOMEM ; 
 struct hvc_struct* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_WORK (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int MAX_NR_HVC_CONSOLES ; 
 scalar_t__ atomic_inc_not_zero (int /*<<< orphan*/ *) ; 
 struct hv_ops const** cons_ops ; 
 int /*<<< orphan*/  hvc_check_console (int) ; 
 int hvc_init () ; 
 int /*<<< orphan*/  hvc_needs_init ; 
 int /*<<< orphan*/  hvc_port_ops ; 
 int /*<<< orphan*/  hvc_set_winsz ; 
 int /*<<< orphan*/  hvc_structs ; 
 int /*<<< orphan*/  hvc_structs_mutex ; 
 struct hvc_struct* kzalloc (int,int /*<<< orphan*/ ) ; 
 int last_hvc ; 
 int /*<<< orphan*/  list_add_tail (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tty_port_init (TYPE_1__*) ; 
 scalar_t__* vtermnos ; 

struct hvc_struct *hvc_alloc(uint32_t vtermno, int data,
			     const struct hv_ops *ops,
			     int outbuf_size)
{
	struct hvc_struct *hp;
	int i;

	/* We wait until a driver actually comes along */
	if (atomic_inc_not_zero(&hvc_needs_init)) {
		int err = hvc_init();
		if (err)
			return ERR_PTR(err);
	}

	hp = kzalloc(ALIGN(sizeof(*hp), sizeof(long)) + outbuf_size,
			GFP_KERNEL);
	if (!hp)
		return ERR_PTR(-ENOMEM);

	hp->vtermno = vtermno;
	hp->data = data;
	hp->ops = ops;
	hp->outbuf_size = outbuf_size;
	hp->outbuf = &((char *)hp)[ALIGN(sizeof(*hp), sizeof(long))];

	tty_port_init(&hp->port);
	hp->port.ops = &hvc_port_ops;

	INIT_WORK(&hp->tty_resize, hvc_set_winsz);
	spin_lock_init(&hp->lock);
	mutex_lock(&hvc_structs_mutex);

	/*
	 * find index to use:
	 * see if this vterm id matches one registered for console.
	 */
	for (i=0; i < MAX_NR_HVC_CONSOLES; i++)
		if (vtermnos[i] == hp->vtermno &&
		    cons_ops[i] == hp->ops)
			break;

	/* no matching slot, just use a counter */
	if (i >= MAX_NR_HVC_CONSOLES)
		i = ++last_hvc;

	hp->index = i;
	cons_ops[i] = ops;
	vtermnos[i] = vtermno;

	list_add_tail(&(hp->next), &hvc_structs);
	mutex_unlock(&hvc_structs_mutex);

	/* check if we need to re-register the kernel console */
	hvc_check_console(i);

	return hp;
}