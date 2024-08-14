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
struct il_channel_info {int flags; } ;

/* Variables and functions */
 int EEPROM_CHANNEL_IBSS ; 

__attribute__((used)) static inline int
il_is_channel_ibss(const struct il_channel_info *ch)
{
	return (ch->flags & EEPROM_CHANNEL_IBSS) ? 1 : 0;
}