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
struct cm_req_msg {int /*<<< orphan*/  offset32; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (int) ; 

__attribute__((used)) static inline void cm_req_set_local_qpn(struct cm_req_msg *req_msg, __be32 qpn)
{
	req_msg->offset32 = cpu_to_be32((be32_to_cpu(qpn) << 8) |
					 (be32_to_cpu(req_msg->offset32) &
					  0x000000FF));
}