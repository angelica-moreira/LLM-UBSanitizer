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
struct ac97_controller {int dummy; } ;

/* Variables and functions */
 int pxa2xx_ac97_read (int,unsigned short) ; 

__attribute__((used)) static int pxa2xx_ac97_read_actrl(struct ac97_controller *adrv, int slot,
				  unsigned short reg)
{
	return pxa2xx_ac97_read(slot, reg);
}