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
struct in_ifaddr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct in_ifaddr* kzalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct in_ifaddr *inet_alloc_ifa(void)
{
	return kzalloc(sizeof(struct in_ifaddr), GFP_KERNEL);
}