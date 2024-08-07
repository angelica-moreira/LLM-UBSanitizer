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
struct efx_nic {int dummy; } ;

/* Variables and functions */
 unsigned int efx_vf_size (struct efx_nic*) ; 

__attribute__((used)) static bool bad_vf_index(struct efx_nic *efx, unsigned index)
{
	return index >= efx_vf_size(efx);
}