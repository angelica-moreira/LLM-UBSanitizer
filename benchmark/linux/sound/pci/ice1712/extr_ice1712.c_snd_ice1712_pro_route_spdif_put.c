#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_kcontrol {int dummy; } ;
struct snd_ice1712 {int /*<<< orphan*/  reg_lock; } ;
struct TYPE_3__ {int* item; } ;
struct TYPE_4__ {TYPE_1__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_2__ value; int /*<<< orphan*/  id; } ;

/* Variables and functions */
 int /*<<< orphan*/  ICEMT (struct snd_ice1712*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ROUTE_SPDOUT ; 
 unsigned int inw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outw (unsigned int,int /*<<< orphan*/ ) ; 
 int snd_ctl_get_ioffidx (struct snd_kcontrol*,int /*<<< orphan*/ *) ; 
 struct snd_ice1712* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int snd_ice1712_pro_route_spdif_put(struct snd_kcontrol *kcontrol,
					   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
	int change, shift;
	int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
	unsigned int val, old_val, nval;

	/* update SPDOUT */
	spin_lock_irq(&ice->reg_lock);
	val = old_val = inw(ICEMT(ice, ROUTE_SPDOUT));
	if (ucontrol->value.enumerated.item[0] >= 11)
		nval = 1;
	else if (ucontrol->value.enumerated.item[0] >= 9)
		nval = 3;
	else if (ucontrol->value.enumerated.item[0] >= 1)
		nval = 2;
	else
		nval = 0;
	shift = idx * 2;
	val &= ~(0x03 << shift);
	val |= nval << shift;
	shift = idx * 4 + 8;
	if (nval == 2) {
		nval = ucontrol->value.enumerated.item[0] - 1;
		val &= ~(0x07 << shift);
		val |= nval << shift;
	} else if (nval == 3) {
		nval = (ucontrol->value.enumerated.item[0] - 9) << 3;
		val &= ~(0x08 << shift);
		val |= nval << shift;
	}
	change = val != old_val;
	if (change)
		outw(val, ICEMT(ice, ROUTE_SPDOUT));
	spin_unlock_irq(&ice->reg_lock);
	return change;
}