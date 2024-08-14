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
struct cm_req_msg {int /*<<< orphan*/  offset40; } ;

/* Variables and functions */
 int be32_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u8 cm_req_get_remote_resp_timeout(struct cm_req_msg *req_msg)
{
	return (u8) ((be32_to_cpu(req_msg->offset40) & 0xF8) >> 3);
}