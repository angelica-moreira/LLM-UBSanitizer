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
typedef  int u32 ;

/* Variables and functions */
 int ioread32be (scalar_t__) ; 
 scalar_t__ qm_ccsr_start ; 

__attribute__((used)) static inline u32 qm_ccsr_in(u32 offset)
{
	return ioread32be(qm_ccsr_start + offset/4);
}