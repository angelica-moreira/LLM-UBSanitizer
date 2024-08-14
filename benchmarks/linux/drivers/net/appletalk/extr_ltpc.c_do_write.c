#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct net_device {int dummy; } ;
struct TYPE_3__ {int cbuflen; int dbuflen; int QWrite; int mailbox; void* dbuf; void* cbuf; } ;

/* Variables and functions */
 int /*<<< orphan*/  enQ (TYPE_1__*) ; 
 int getmbox () ; 
 int /*<<< orphan*/  idle (struct net_device*) ; 
 int* mailbox ; 
 scalar_t__* mboxinuse ; 
 int /*<<< orphan*/  printk (char*) ; 
 TYPE_1__* qels ; 

__attribute__((used)) static int do_write(struct net_device *dev, void *cbuf, int cbuflen,
	void *dbuf, int dbuflen)
{

	int i = getmbox();
	int ret;

	if(i) {
		qels[i].cbuf = cbuf;
		qels[i].cbuflen = cbuflen;
		qels[i].dbuf = dbuf;
		qels[i].dbuflen = dbuflen;
		qels[i].QWrite = 1;
		qels[i].mailbox = i;  /* this should be initted rather */
		enQ(&qels[i]);
		idle(dev);
		ret = mailbox[i];
		mboxinuse[i]=0;
		return ret;
	}
	printk("ltpc: could not allocate mbox\n");
	return -1;
}