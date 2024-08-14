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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct hns_roce_eq {int entries; TYPE_1__* buf_list; } ;
struct hns_roce_ceqe {int dummy; } ;
struct TYPE_2__ {scalar_t__ buf; } ;

/* Variables and functions */
 unsigned long HNS_ROCE_BA_SIZE ; 
 int HNS_ROCE_CEQ_ENTRY_SIZE ; 

__attribute__((used)) static struct hns_roce_ceqe *get_ceqe_v1(struct hns_roce_eq *eq, u32 entry)
{
	unsigned long off = (entry & (eq->entries - 1)) *
			     HNS_ROCE_CEQ_ENTRY_SIZE;

	return (struct hns_roce_ceqe *)((u8 *)
			(eq->buf_list[off / HNS_ROCE_BA_SIZE].buf) +
			off % HNS_ROCE_BA_SIZE);
}