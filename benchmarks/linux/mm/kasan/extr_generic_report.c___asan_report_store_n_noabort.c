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
 int /*<<< orphan*/  _RET_IP_ ; 
 int /*<<< orphan*/  kasan_report (unsigned long,size_t,int,int /*<<< orphan*/ ) ; 

void __asan_report_store_n_noabort(unsigned long addr, size_t size)
{
	kasan_report(addr, size, true, _RET_IP_);
}