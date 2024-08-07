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
typedef  scalar_t__ u32 ;
struct TYPE_2__ {scalar_t__ gsi_base; } ;

/* Variables and functions */
 TYPE_1__* mp_ioapic_gsi_routing (int) ; 

__attribute__((used)) static inline u32 mp_pin_to_gsi(int ioapic, int pin)
{
	return mp_ioapic_gsi_routing(ioapic)->gsi_base + pin;
}