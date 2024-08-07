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
struct rvt_qp {int /*<<< orphan*/  s_last_psn; } ;

/* Variables and functions */

__attribute__((used)) static inline void update_last_psn(struct rvt_qp *qp, u32 psn)
{
	qp->s_last_psn = psn;
}