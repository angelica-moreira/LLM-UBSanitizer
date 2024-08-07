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
typedef  int u8 ;
struct cm_req_msg {int offset51; } ;

/* Variables and functions */

__attribute__((used)) static inline void cm_req_set_max_cm_retries(struct cm_req_msg *req_msg,
					     u8 retries)
{
	req_msg->offset51 = (u8) ((req_msg->offset51 & 0xF) | (retries << 4));
}