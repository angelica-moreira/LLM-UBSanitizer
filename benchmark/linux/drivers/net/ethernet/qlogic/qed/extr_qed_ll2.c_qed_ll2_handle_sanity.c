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
typedef  int /*<<< orphan*/  u8 ;
struct qed_ll2_info {int dummy; } ;
struct qed_hwfn {int dummy; } ;

/* Variables and functions */
 struct qed_ll2_info* __qed_ll2_handle_sanity (struct qed_hwfn*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static struct qed_ll2_info *qed_ll2_handle_sanity(struct qed_hwfn *p_hwfn,
						  u8 connection_handle)
{
	return __qed_ll2_handle_sanity(p_hwfn, connection_handle, false, true);
}