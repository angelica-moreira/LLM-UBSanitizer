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
struct snd_sb {int /*<<< orphan*/  mixer_lock; } ;
struct snd_kcontrol {int private_value; } ;
struct TYPE_3__ {int* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;

/* Variables and functions */
 struct snd_sb* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 unsigned char snd_sbmixer_read (struct snd_sb*,int) ; 
 int /*<<< orphan*/  snd_sbmixer_write (struct snd_sb*,int,unsigned char) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int snd_sbmixer_put_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_sb *sb = snd_kcontrol_chip(kcontrol);
	unsigned long flags;
	int left_reg = kcontrol->private_value & 0xff;
	int right_reg = (kcontrol->private_value >> 8) & 0xff;
	int left_shift = (kcontrol->private_value >> 16) & 0x07;
	int right_shift = (kcontrol->private_value >> 19) & 0x07;
	int mask = (kcontrol->private_value >> 24) & 0xff;
	int change;
	unsigned char left, right, oleft, oright;

	left = (ucontrol->value.integer.value[0] & mask) << left_shift;
	right = (ucontrol->value.integer.value[1] & mask) << right_shift;
	spin_lock_irqsave(&sb->mixer_lock, flags);
	if (left_reg == right_reg) {
		oleft = snd_sbmixer_read(sb, left_reg);
		left = (oleft & ~((mask << left_shift) | (mask << right_shift))) | left | right;
		change = left != oleft;
		if (change)
			snd_sbmixer_write(sb, left_reg, left);
	} else {
		oleft = snd_sbmixer_read(sb, left_reg);
		oright = snd_sbmixer_read(sb, right_reg);
		left = (oleft & ~(mask << left_shift)) | left;
		right = (oright & ~(mask << right_shift)) | right;
		change = left != oleft || right != oright;
		if (change) {
			snd_sbmixer_write(sb, left_reg, left);
			snd_sbmixer_write(sb, right_reg, right);
		}
	}
	spin_unlock_irqrestore(&sb->mixer_lock, flags);
	return change;
}