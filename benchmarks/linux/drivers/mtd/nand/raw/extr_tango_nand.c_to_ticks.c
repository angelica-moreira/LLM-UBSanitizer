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
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  DIV_ROUND_UP_ULL (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NSEC_PER_SEC ; 

__attribute__((used)) static u32 to_ticks(int kHz, int ps)
{
	return DIV_ROUND_UP_ULL((u64)kHz * ps, NSEC_PER_SEC);
}