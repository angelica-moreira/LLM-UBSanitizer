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
struct cm_req_msg {int primary_offset94; } ;

/* Variables and functions */

__attribute__((used)) static inline void cm_req_set_primary_sl(struct cm_req_msg *req_msg, u8 sl)
{
	req_msg->primary_offset94 = (u8) ((req_msg->primary_offset94 & 0x0F) |
					  (sl << 4));
}