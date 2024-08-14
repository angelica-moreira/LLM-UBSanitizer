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
struct TYPE_2__ {int in_use; int size; } ;
struct t4_wq {TYPE_1__ sq; } ;

/* Variables and functions */

__attribute__((used)) static inline int t4_sq_full(struct t4_wq *wq)
{
	return wq->sq.in_use == (wq->sq.size - 1);
}