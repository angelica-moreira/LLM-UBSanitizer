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
struct vx_core {int dummy; } ;
struct snd_vxpocket {unsigned long port; } ;

/* Variables and functions */
 struct snd_vxpocket* to_vxpocket (struct vx_core*) ; 
 unsigned long* vxp_reg_offset ; 

__attribute__((used)) static inline unsigned long vxp_reg_addr(struct vx_core *_chip, int reg)
{
	struct snd_vxpocket *chip = to_vxpocket(_chip);
	return chip->port + vxp_reg_offset[reg];
}