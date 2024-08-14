#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int u32 ;
struct rvt_sge {scalar_t__ length; scalar_t__ sge_length; scalar_t__ n; scalar_t__ m; TYPE_3__* mr; scalar_t__ vaddr; } ;
struct rvt_sge_state {scalar_t__ num_sge; struct rvt_sge sge; struct rvt_sge* sg_list; } ;
struct TYPE_6__ {scalar_t__ mapsz; TYPE_2__** map; scalar_t__ lkey; } ;
struct TYPE_5__ {TYPE_1__* segs; } ;
struct TYPE_4__ {scalar_t__ length; scalar_t__ vaddr; } ;

/* Variables and functions */
 scalar_t__ RVT_SEGSZ ; 
 int rvt_get_sge_length (struct rvt_sge*,int) ; 

__attribute__((used)) static u32 qib_count_sge(struct rvt_sge_state *ss, u32 length)
{
	struct rvt_sge *sg_list = ss->sg_list;
	struct rvt_sge sge = ss->sge;
	u8 num_sge = ss->num_sge;
	u32 ndesc = 1;  /* count the header */

	while (length) {
		u32 len = rvt_get_sge_length(&sge, length);

		if (((long) sge.vaddr & (sizeof(u32) - 1)) ||
		    (len != length && (len & (sizeof(u32) - 1)))) {
			ndesc = 0;
			break;
		}
		ndesc++;
		sge.vaddr += len;
		sge.length -= len;
		sge.sge_length -= len;
		if (sge.sge_length == 0) {
			if (--num_sge)
				sge = *sg_list++;
		} else if (sge.length == 0 && sge.mr->lkey) {
			if (++sge.n >= RVT_SEGSZ) {
				if (++sge.m >= sge.mr->mapsz)
					break;
				sge.n = 0;
			}
			sge.vaddr =
				sge.mr->map[sge.m]->segs[sge.n].vaddr;
			sge.length =
				sge.mr->map[sge.m]->segs[sge.n].length;
		}
		length -= len;
	}
	return ndesc;
}