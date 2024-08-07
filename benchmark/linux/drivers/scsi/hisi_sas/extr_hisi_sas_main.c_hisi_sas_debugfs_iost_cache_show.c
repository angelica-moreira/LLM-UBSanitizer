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
struct seq_file {struct hisi_hba* private; } ;
struct hisi_sas_iost_itct_cache {int* data; } ;
struct hisi_hba {scalar_t__ debugfs_iost_cache; } ;
typedef  int /*<<< orphan*/  __le64 ;

/* Variables and functions */
 int HISI_SAS_IOST_ITCT_CACHE_DW_SZ ; 
 int HISI_SAS_IOST_ITCT_CACHE_NUM ; 
 int /*<<< orphan*/  hisi_sas_show_row_64 (struct seq_file*,int,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int hisi_sas_debugfs_iost_cache_show(struct seq_file *s, void *p)
{
	struct hisi_hba *hisi_hba = s->private;
	struct hisi_sas_iost_itct_cache *iost_cache =
		(struct hisi_sas_iost_itct_cache *)hisi_hba->debugfs_iost_cache;
	u32 cache_size = HISI_SAS_IOST_ITCT_CACHE_DW_SZ * 4;
	int i, tab_idx;
	__le64 *iost;

	for (i = 0; i < HISI_SAS_IOST_ITCT_CACHE_NUM; i++, iost_cache++) {
		/*
		 * Data struct of IOST cache:
		 * Data[1]: BIT0~15: Table index
		 *	    Bit16:   Valid mask
		 * Data[2]~[9]: IOST table
		 */
		tab_idx = (iost_cache->data[1] & 0xffff);
		iost = (__le64 *)iost_cache;

		hisi_sas_show_row_64(s, tab_idx, cache_size, iost);
	}

	return 0;
}