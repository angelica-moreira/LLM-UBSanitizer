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
struct snd_opl3 {TYPE_1__* card; } ;
struct TYPE_2__ {int /*<<< orphan*/  module; } ;

/* Variables and functions */
 int EFAULT ; 
 int /*<<< orphan*/  try_module_get (int /*<<< orphan*/ ) ; 

int snd_opl3_synth_use_inc(struct snd_opl3 * opl3)
{
	if (!try_module_get(opl3->card->module))
		return -EFAULT;
	return 0;

}