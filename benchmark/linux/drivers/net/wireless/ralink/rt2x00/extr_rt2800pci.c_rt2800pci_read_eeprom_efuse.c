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
struct rt2x00_dev {int dummy; } ;

/* Variables and functions */
 int rt2800_read_eeprom_efuse (struct rt2x00_dev*) ; 

__attribute__((used)) static inline int rt2800pci_read_eeprom_efuse(struct rt2x00_dev *rt2x00dev)
{
	return rt2800_read_eeprom_efuse(rt2x00dev);
}