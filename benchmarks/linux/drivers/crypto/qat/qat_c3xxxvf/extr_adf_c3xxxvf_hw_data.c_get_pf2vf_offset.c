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
 int /*<<< orphan*/  ADF_C3XXXIOV_PF2VF_OFFSET ; 

__attribute__((used)) static u32 get_pf2vf_offset(u32 i)
{
	return ADF_C3XXXIOV_PF2VF_OFFSET;
}