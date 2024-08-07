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
struct siw_sqe {int /*<<< orphan*/  flags; } ;
struct siw_qp {int dummy; } ;

/* Variables and functions */
 scalar_t__ READ_ONCE (int /*<<< orphan*/ ) ; 
 struct siw_sqe* orq_get_tail (struct siw_qp*) ; 

__attribute__((used)) static inline struct siw_sqe *orq_get_free(struct siw_qp *qp)
{
	struct siw_sqe *orq_e = orq_get_tail(qp);

	if (orq_e && READ_ONCE(orq_e->flags) == 0)
		return orq_e;

	return NULL;
}