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
typedef  int u8 ;

/* Variables and functions */
 int MSI_STANDARD_EC_3G_MASK ; 
 int /*<<< orphan*/  MSI_STANDARD_EC_DEVICES_EXISTS_ADDRESS ; 
 int ec_read (int /*<<< orphan*/ ,int*) ; 
 int threeg_exists ; 

__attribute__((used)) static int get_threeg_exists(void)
{
	u8 rdata;
	int result;

	result = ec_read(MSI_STANDARD_EC_DEVICES_EXISTS_ADDRESS, &rdata);
	if (result < 0)
		return result;

	threeg_exists = !!(rdata & MSI_STANDARD_EC_3G_MASK);

	return 0;
}