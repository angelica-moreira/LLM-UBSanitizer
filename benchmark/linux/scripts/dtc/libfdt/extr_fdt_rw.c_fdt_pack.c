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
struct fdt_reserve_entry {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FDT_RW_PROBE (void*) ; 
 int /*<<< orphan*/  fdt_data_size_ (void*) ; 
 int fdt_num_mem_rsv (void*) ; 
 int /*<<< orphan*/  fdt_packblocks_ (void*,void*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fdt_set_totalsize (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fdt_size_dt_struct (void*) ; 

int fdt_pack(void *fdt)
{
	int mem_rsv_size;

	FDT_RW_PROBE(fdt);

	mem_rsv_size = (fdt_num_mem_rsv(fdt)+1)
		* sizeof(struct fdt_reserve_entry);
	fdt_packblocks_(fdt, fdt, mem_rsv_size, fdt_size_dt_struct(fdt));
	fdt_set_totalsize(fdt, fdt_data_size_(fdt));

	return 0;
}