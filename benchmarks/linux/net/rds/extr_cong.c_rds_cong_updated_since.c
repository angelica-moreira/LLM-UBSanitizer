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

/* Variables and functions */
 unsigned long atomic_read (int /*<<< orphan*/ *) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  rds_cong_generation ; 

int rds_cong_updated_since(unsigned long *recent)
{
	unsigned long gen = atomic_read(&rds_cong_generation);

	if (likely(*recent == gen))
		return 0;
	*recent = gen;
	return 1;
}