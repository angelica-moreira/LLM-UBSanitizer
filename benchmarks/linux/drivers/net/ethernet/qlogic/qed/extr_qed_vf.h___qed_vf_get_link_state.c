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
struct qed_mcp_link_state {int dummy; } ;
struct qed_hwfn {int dummy; } ;
struct qed_bulletin_content {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void __qed_vf_get_link_state(struct qed_hwfn *p_hwfn,
					   struct qed_mcp_link_state *p_link,
					   struct qed_bulletin_content
					   *p_bulletin)
{
}