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
struct TYPE_2__ {unsigned int __nmi_count; } ;

/* Variables and functions */
 TYPE_1__ cpu_data (int) ; 

__attribute__((used)) static inline unsigned int get_nmi_count(int cpu)
{
	return cpu_data(cpu).__nmi_count;
}