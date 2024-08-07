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
typedef  int u32 ;
struct qbman_fq_query_np_rslt {int /*<<< orphan*/  frm_cnt; } ;

/* Variables and functions */
 int le32_to_cpu (int /*<<< orphan*/ ) ; 

u32 qbman_fq_state_frame_count(const struct qbman_fq_query_np_rslt *r)
{
	return (le32_to_cpu(r->frm_cnt) & 0x00FFFFFF);
}