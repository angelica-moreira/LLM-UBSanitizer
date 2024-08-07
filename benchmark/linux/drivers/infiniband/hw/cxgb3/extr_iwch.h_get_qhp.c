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
typedef  int /*<<< orphan*/  u32 ;
struct iwch_qp {int dummy; } ;
struct iwch_dev {int /*<<< orphan*/  qps; } ;

/* Variables and functions */
 struct iwch_qp* xa_load (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct iwch_qp *get_qhp(struct iwch_dev *rhp, u32 qpid)
{
	return xa_load(&rhp->qps, qpid);
}