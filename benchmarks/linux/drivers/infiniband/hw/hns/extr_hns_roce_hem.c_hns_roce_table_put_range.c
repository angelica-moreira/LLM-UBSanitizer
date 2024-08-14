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
struct hns_roce_hem_table {unsigned long table_chunk_size; unsigned long obj_size; int /*<<< orphan*/  type; } ;
struct hns_roce_hem_mhop {unsigned long bt_chunk_size; } ;
struct hns_roce_dev {int dummy; } ;

/* Variables and functions */
 scalar_t__ hns_roce_calc_hem_mhop (struct hns_roce_dev*,struct hns_roce_hem_table*,int /*<<< orphan*/ *,struct hns_roce_hem_mhop*) ; 
 scalar_t__ hns_roce_check_whether_mhop (struct hns_roce_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hns_roce_table_put (struct hns_roce_dev*,struct hns_roce_hem_table*,unsigned long) ; 

void hns_roce_table_put_range(struct hns_roce_dev *hr_dev,
			      struct hns_roce_hem_table *table,
			      unsigned long start, unsigned long end)
{
	struct hns_roce_hem_mhop mhop;
	unsigned long inc = table->table_chunk_size / table->obj_size;
	unsigned long i;

	if (hns_roce_check_whether_mhop(hr_dev, table->type)) {
		if (hns_roce_calc_hem_mhop(hr_dev, table, NULL, &mhop))
			return;
		inc = mhop.bt_chunk_size / table->obj_size;
	}

	for (i = start; i <= end; i += inc)
		hns_roce_table_put(hr_dev, table, i);
}