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
typedef  scalar_t__ u64 ;
struct nicvf {scalar_t__ reg_base; } ;

/* Variables and functions */
 scalar_t__ readq_relaxed (scalar_t__) ; 

u64 nicvf_reg_read(struct nicvf *nic, u64 offset)
{
	return readq_relaxed(nic->reg_base + offset);
}