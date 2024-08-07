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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  tmp ;
typedef  int /*<<< orphan*/  fdt64_t ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_fdt64 (int /*<<< orphan*/ ) ; 
 int fdt_setprop (void*,int,char const*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline int fdt_setprop_u64(void *fdt, int nodeoffset, const char *name,
				  uint64_t val)
{
	fdt64_t tmp = cpu_to_fdt64(val);
	return fdt_setprop(fdt, nodeoffset, name, &tmp, sizeof(tmp));
}