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
struct snd_ac97 {int /*<<< orphan*/ * build_ops; } ;

/* Variables and functions */
 int /*<<< orphan*/  patch_it2646_ops ; 
 int /*<<< orphan*/  snd_ac97_write_cache (struct snd_ac97*,int,int) ; 

__attribute__((used)) static int patch_it2646(struct snd_ac97 * ac97)
{
	ac97->build_ops = &patch_it2646_ops;
	/* full DAC volume */
	snd_ac97_write_cache(ac97, 0x5E, 0x0808);
	snd_ac97_write_cache(ac97, 0x7A, 0x0808);
	return 0;
}