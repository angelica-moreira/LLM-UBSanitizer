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
struct ib_qp {int dummy; } ;

/* Variables and functions */
 int mlx5_ib_qp_set_counter (struct ib_qp*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int mlx5_ib_counter_unbind_qp(struct ib_qp *qp)
{
	return mlx5_ib_qp_set_counter(qp, NULL);
}