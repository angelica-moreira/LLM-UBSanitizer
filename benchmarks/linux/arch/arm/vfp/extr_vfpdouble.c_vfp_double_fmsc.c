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
typedef  int /*<<< orphan*/  u32 ;

/* Variables and functions */
 int /*<<< orphan*/  NEG_SUBTRACT ; 
 int /*<<< orphan*/  vfp_double_multiply_accumulate (int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static u32 vfp_double_fmsc(int dd, int dn, int dm, u32 fpscr)
{
	return vfp_double_multiply_accumulate(dd, dn, dm, fpscr, NEG_SUBTRACT, "fmsc");
}