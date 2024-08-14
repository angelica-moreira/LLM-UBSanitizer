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
struct hns_roce_v2_cqe {int dummy; } ;
struct hns_roce_cq {int /*<<< orphan*/  cons_index; } ;

/* Variables and functions */
 struct hns_roce_v2_cqe* get_sw_cqe_v2 (struct hns_roce_cq*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct hns_roce_v2_cqe *next_cqe_sw_v2(struct hns_roce_cq *hr_cq)
{
	return get_sw_cqe_v2(hr_cq, hr_cq->cons_index);
}