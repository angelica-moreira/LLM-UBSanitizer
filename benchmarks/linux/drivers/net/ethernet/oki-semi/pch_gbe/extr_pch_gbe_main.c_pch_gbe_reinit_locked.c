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
struct pch_gbe_adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pch_gbe_down (struct pch_gbe_adapter*) ; 
 int /*<<< orphan*/  pch_gbe_up (struct pch_gbe_adapter*) ; 

void pch_gbe_reinit_locked(struct pch_gbe_adapter *adapter)
{
	pch_gbe_down(adapter);
	pch_gbe_up(adapter);
}