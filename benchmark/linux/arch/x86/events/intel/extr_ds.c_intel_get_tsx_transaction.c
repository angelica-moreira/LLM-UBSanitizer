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

/* Variables and functions */
 int PEBS_HSW_TSX_FLAGS ; 
 int PERF_TXN_ABORT_SHIFT ; 
 int PERF_TXN_TRANSACTION ; 

__attribute__((used)) static inline u64 intel_get_tsx_transaction(u64 tsx_tuning, u64 ax)
{
	u64 txn = (tsx_tuning & PEBS_HSW_TSX_FLAGS) >> 32;

	/* For RTM XABORTs also log the abort code from AX */
	if ((txn & PERF_TXN_TRANSACTION) && (ax & 1))
		txn |= ((ax >> 24) & 0xff) << PERF_TXN_ABORT_SHIFT;
	return txn;
}