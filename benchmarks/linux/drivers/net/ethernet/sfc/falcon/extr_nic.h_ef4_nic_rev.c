#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct ef4_nic {TYPE_1__* type; } ;
struct TYPE_2__ {int revision; } ;

/* Variables and functions */

__attribute__((used)) static inline int ef4_nic_rev(struct ef4_nic *efx)
{
	return efx->type->revision;
}