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
struct TYPE_3__ {unsigned long long val; char sym; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 TYPE_1__* mark ; 

char trace_find_mark(unsigned long long d)
{
	int i;
	int size = ARRAY_SIZE(mark);

	for (i = 0; i < size; i++) {
		if (d > mark[i].val)
			break;
	}

	return (i == size) ? ' ' : mark[i].sym;
}