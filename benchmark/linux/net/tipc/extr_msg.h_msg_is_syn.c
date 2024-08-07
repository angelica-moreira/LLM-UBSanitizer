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
struct tipc_msg {int dummy; } ;

/* Variables and functions */
 int msg_bits (struct tipc_msg*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static inline int msg_is_syn(struct tipc_msg *m)
{
	return msg_bits(m, 0, 17, 1);
}