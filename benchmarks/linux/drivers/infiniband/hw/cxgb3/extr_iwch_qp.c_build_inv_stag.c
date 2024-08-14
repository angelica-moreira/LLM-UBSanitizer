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
struct TYPE_4__ {scalar_t__ reserved; int /*<<< orphan*/  stag; } ;
union t3_wr {TYPE_2__ local_inv; } ;
typedef  int u8 ;
struct t3_local_inv_wr {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  invalidate_rkey; } ;
struct ib_send_wr {TYPE_1__ ex; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_be32 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int build_inv_stag(union t3_wr *wqe, const struct ib_send_wr *wr,
			  u8 *flit_cnt)
{
	wqe->local_inv.stag = cpu_to_be32(wr->ex.invalidate_rkey);
	wqe->local_inv.reserved = 0;
	*flit_cnt = sizeof(struct t3_local_inv_wr) >> 3;
	return 0;
}