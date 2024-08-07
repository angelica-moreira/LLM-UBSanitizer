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
 int /*<<< orphan*/  PVRDMA_ACCESS_FLAGS_MAX ; 
 int PVRDMA_MASK (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int pvrdma_access_flags_to_ib(int flags)
{
	return flags & PVRDMA_MASK(PVRDMA_ACCESS_FLAGS_MAX);
}