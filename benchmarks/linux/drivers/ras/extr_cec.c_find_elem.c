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
typedef  int /*<<< orphan*/  u64 ;
struct ce_array {int /*<<< orphan*/  n; } ;

/* Variables and functions */
 int ENOKEY ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int __find_elem (struct ce_array*,int /*<<< orphan*/ ,unsigned int*) ; 

__attribute__((used)) static int find_elem(struct ce_array *ca, u64 pfn, unsigned int *to)
{
	WARN_ON(!to);

	if (!ca->n) {
		*to = 0;
		return -ENOKEY;
	}
	return __find_elem(ca, pfn, to);
}