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
typedef  int /*<<< orphan*/  uncond ;
struct arpt_entry {int target_offset; int /*<<< orphan*/  arp; } ;
struct arpt_arp {int dummy; } ;

/* Variables and functions */
 scalar_t__ memcmp (int /*<<< orphan*/ *,struct arpt_arp const*,int) ; 

__attribute__((used)) static inline bool unconditional(const struct arpt_entry *e)
{
	static const struct arpt_arp uncond;

	return e->target_offset == sizeof(struct arpt_entry) &&
	       memcmp(&e->arp, &uncond, sizeof(uncond)) == 0;
}