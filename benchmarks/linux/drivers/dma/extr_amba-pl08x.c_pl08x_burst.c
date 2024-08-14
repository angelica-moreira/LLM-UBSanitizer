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
typedef  scalar_t__ u32 ;
struct TYPE_3__ {scalar_t__ burstwords; scalar_t__ reg; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 TYPE_1__* burst_sizes ; 

__attribute__((used)) static u32 pl08x_burst(u32 maxburst)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(burst_sizes); i++)
		if (burst_sizes[i].burstwords <= maxburst)
			break;

	return burst_sizes[i].reg;
}