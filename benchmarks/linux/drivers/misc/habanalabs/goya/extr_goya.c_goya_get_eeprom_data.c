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
struct hl_device {struct goya_device* asic_specific; } ;
struct goya_device {int hw_cap_initialized; } ;

/* Variables and functions */
 int HW_CAP_CPU_Q ; 
 int hl_fw_get_eeprom_data (struct hl_device*,void*,size_t) ; 

__attribute__((used)) static int goya_get_eeprom_data(struct hl_device *hdev, void *data,
				size_t max_size)
{
	struct goya_device *goya = hdev->asic_specific;

	if (!(goya->hw_cap_initialized & HW_CAP_CPU_Q))
		return 0;

	return hl_fw_get_eeprom_data(hdev, data, max_size);
}