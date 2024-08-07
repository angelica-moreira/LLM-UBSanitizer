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
struct recv_buf {struct adapter* adapter; int /*<<< orphan*/  recvbuf_lock; int /*<<< orphan*/  list; } ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void initrecvbuf(struct recv_buf *precvbuf, struct adapter *padapter)
{
	INIT_LIST_HEAD(&precvbuf->list);
	spin_lock_init(&precvbuf->recvbuf_lock);

	precvbuf->adapter = padapter;
}