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
struct dst_entry {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static struct dst_entry *ipv4_blackhole_dst_check(struct dst_entry *dst, u32 cookie)
{
	return NULL;
}