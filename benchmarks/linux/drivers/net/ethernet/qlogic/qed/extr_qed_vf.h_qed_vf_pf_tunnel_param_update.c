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
struct qed_tunnel_info {int dummy; } ;
struct qed_hwfn {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 

__attribute__((used)) static inline int qed_vf_pf_tunnel_param_update(struct qed_hwfn *p_hwfn,
						struct qed_tunnel_info *p_tunn)
{
	return -EINVAL;
}