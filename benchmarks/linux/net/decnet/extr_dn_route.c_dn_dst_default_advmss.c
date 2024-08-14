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
struct dst_entry {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 unsigned int dn_mss_from_pmtu (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dst_mtu (struct dst_entry const*) ; 

__attribute__((used)) static unsigned int dn_dst_default_advmss(const struct dst_entry *dst)
{
	return dn_mss_from_pmtu(dst->dev, dst_mtu(dst));
}