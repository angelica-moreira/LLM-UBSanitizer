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
struct in_device {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  __ip_mc_inc_group (struct in_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void ip_mc_inc_group(struct in_device *in_dev, __be32 addr)
{
	__ip_mc_inc_group(in_dev, addr, GFP_KERNEL);
}