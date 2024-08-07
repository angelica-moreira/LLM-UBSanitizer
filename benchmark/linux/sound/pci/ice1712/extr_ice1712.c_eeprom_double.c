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
struct TYPE_2__ {scalar_t__* data; } ;
struct snd_ice1712 {TYPE_1__ eeprom; } ;

/* Variables and functions */

__attribute__((used)) static inline unsigned int eeprom_double(struct snd_ice1712 *ice, int idx)
{
	return (unsigned int)ice->eeprom.data[idx] | ((unsigned int)ice->eeprom.data[idx + 1] << 8);
}