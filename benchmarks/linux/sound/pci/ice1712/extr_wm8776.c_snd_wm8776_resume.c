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
struct snd_wm8776 {int /*<<< orphan*/ * regs; } ;

/* Variables and functions */
 int WM8776_REG_COUNT ; 
 int /*<<< orphan*/  snd_wm8776_write (struct snd_wm8776*,int,int /*<<< orphan*/ ) ; 

void snd_wm8776_resume(struct snd_wm8776 *wm)
{
	int i;

	for (i = 0; i < WM8776_REG_COUNT; i++)
		snd_wm8776_write(wm, i, wm->regs[i]);
}