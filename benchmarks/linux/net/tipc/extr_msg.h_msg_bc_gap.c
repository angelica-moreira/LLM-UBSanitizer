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
typedef  int /*<<< orphan*/  u32 ;
struct tipc_msg {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  msg_bits (struct tipc_msg*,int,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline u32 msg_bc_gap(struct tipc_msg *m)
{
	return msg_bits(m, 8, 0, 0x3ff);
}