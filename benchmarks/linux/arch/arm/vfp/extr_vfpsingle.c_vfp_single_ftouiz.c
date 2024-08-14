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
typedef  int /*<<< orphan*/  s32 ;

/* Variables and functions */
 int /*<<< orphan*/  FPSCR_ROUND_TOZERO ; 
 int /*<<< orphan*/  vfp_single_ftoui (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32 vfp_single_ftouiz(int sd, int unused, s32 m, u32 fpscr)
{
	return vfp_single_ftoui(sd, unused, m, FPSCR_ROUND_TOZERO);
}