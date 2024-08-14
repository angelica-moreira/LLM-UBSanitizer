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
struct snd_ac97 {TYPE_1__* bus; } ;
struct TYPE_2__ {int /*<<< orphan*/  card; } ;

/* Variables and functions */
 int /*<<< orphan*/  AC97_WM9704_TEST ; 
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_ac97_cnew (int /*<<< orphan*/ *,struct snd_ac97*) ; 
 int /*<<< orphan*/  snd_ac97_write_cache (struct snd_ac97*,int /*<<< orphan*/ ,int) ; 
 int snd_ctl_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * wm9704_snd_ac97_controls ; 

__attribute__((used)) static int patch_wolfson_wm9704_specific(struct snd_ac97 * ac97)
{
	int err, i;
	for (i = 0; i < ARRAY_SIZE(wm9704_snd_ac97_controls); i++) {
		if ((err = snd_ctl_add(ac97->bus->card, snd_ac97_cnew(&wm9704_snd_ac97_controls[i], ac97))) < 0)
			return err;
	}
	/* patch for DVD noise */
	snd_ac97_write_cache(ac97, AC97_WM9704_TEST, 0x0200);
	return 0;
}