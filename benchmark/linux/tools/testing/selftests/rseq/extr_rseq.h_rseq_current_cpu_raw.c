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
typedef  int /*<<< orphan*/  int32_t ;
struct TYPE_2__ {int /*<<< orphan*/  cpu_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  RSEQ_ACCESS_ONCE (int /*<<< orphan*/ ) ; 
 TYPE_1__ __rseq_abi ; 

__attribute__((used)) static inline int32_t rseq_current_cpu_raw(void)
{
	return RSEQ_ACCESS_ONCE(__rseq_abi.cpu_id);
}