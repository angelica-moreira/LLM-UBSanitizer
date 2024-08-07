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
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  cpwgr (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void csky_pmu_write_l2rmc(uint64_t val)
{
	cpwgr("<0, 0x32>", (uint32_t)  val);
	cpwgr("<0, 0x33>", (uint32_t) (val >> 32));
}