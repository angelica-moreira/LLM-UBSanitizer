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
typedef  scalar_t__ u32 ;

/* Variables and functions */
 int ARRAY_SIZE (scalar_t__*) ; 
 scalar_t__* coda_supported_firmwares ; 

__attribute__((used)) static bool coda_firmware_supported(u32 vernum)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(coda_supported_firmwares); i++)
		if (vernum == coda_supported_firmwares[i])
			return true;
	return false;
}