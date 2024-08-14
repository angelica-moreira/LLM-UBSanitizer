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
struct pcm512x_priv {int overclock_dsp; } ;

/* Variables and functions */

__attribute__((used)) static unsigned long pcm512x_dsp_max(struct pcm512x_priv *pcm512x)
{
	return 50000000 + 50000000 * pcm512x->overclock_dsp / 100;
}