#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_3__ {scalar_t__ opal_no; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 scalar_t__ be32_to_cpu (int /*<<< orphan*/  const) ; 
 TYPE_1__* ops_info ; 

__attribute__((used)) static int get_nr_attrs(const __be32 *ops, int len)
{
	int i, j;
	int nr_attrs = 0;

	for (i = 0; i < len; i++)
		for (j = 0; j < ARRAY_SIZE(ops_info); j++)
			if (be32_to_cpu(ops[i]) == ops_info[j].opal_no)
				nr_attrs++;

	return nr_attrs;
}