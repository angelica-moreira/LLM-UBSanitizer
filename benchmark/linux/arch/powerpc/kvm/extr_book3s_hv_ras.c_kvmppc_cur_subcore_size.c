#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {TYPE_1__* kvm_split_mode; } ;
struct TYPE_6__ {TYPE_2__ kvm_hstate; } ;
struct TYPE_4__ {int subcore_size; } ;

/* Variables and functions */
 TYPE_3__* local_paca ; 
 int threads_per_subcore ; 

__attribute__((used)) static inline int kvmppc_cur_subcore_size(void)
{
	if (local_paca->kvm_hstate.kvm_split_mode)
		return local_paca->kvm_hstate.kvm_split_mode->subcore_size;

	return threads_per_subcore;
}