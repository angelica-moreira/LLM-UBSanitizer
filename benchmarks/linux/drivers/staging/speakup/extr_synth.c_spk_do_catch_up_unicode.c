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
struct spk_synth {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  _spk_do_catch_up (struct spk_synth*,int) ; 

void spk_do_catch_up_unicode(struct spk_synth *synth)
{
	_spk_do_catch_up(synth, 1);
}