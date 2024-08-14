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
struct zd1201 {int /*<<< orphan*/  mac_enabled; } ;

/* Variables and functions */
 int /*<<< orphan*/  zd1201_disable (struct zd1201*) ; 
 int zd1201_enable (struct zd1201*) ; 

__attribute__((used)) static int zd1201_mac_reset(struct zd1201 *zd)
{
	if (!zd->mac_enabled)
		return 0;
	zd1201_disable(zd);
	return zd1201_enable(zd);
}