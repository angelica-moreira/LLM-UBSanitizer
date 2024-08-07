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
struct TYPE_2__ {int /*<<< orphan*/  reg_data8; int /*<<< orphan*/  reg_regsel; } ;
struct snd_gus_card {TYPE_1__ gf1; } ;

/* Variables and functions */
 unsigned char inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  outb (unsigned char,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline unsigned char __snd_gf1_look8(struct snd_gus_card * gus,
					    unsigned char reg)
{
	outb(reg, gus->gf1.reg_regsel);
	mb();
	return inb(gus->gf1.reg_data8);
}