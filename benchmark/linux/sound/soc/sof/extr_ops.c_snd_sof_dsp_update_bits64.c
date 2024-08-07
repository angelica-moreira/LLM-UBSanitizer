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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct snd_sof_dev {int /*<<< orphan*/  hw_lock; } ;

/* Variables and functions */
 int snd_sof_dsp_update_bits64_unlocked (struct snd_sof_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

bool snd_sof_dsp_update_bits64(struct snd_sof_dev *sdev, u32 bar, u32 offset,
			       u64 mask, u64 value)
{
	unsigned long flags;
	bool change;

	spin_lock_irqsave(&sdev->hw_lock, flags);
	change = snd_sof_dsp_update_bits64_unlocked(sdev, bar, offset, mask,
						    value);
	spin_unlock_irqrestore(&sdev->hw_lock, flags);
	return change;
}