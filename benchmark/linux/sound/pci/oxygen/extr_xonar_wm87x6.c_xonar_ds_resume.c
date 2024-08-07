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
struct oxygen {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  wm8766_registers_init (struct oxygen*) ; 
 int /*<<< orphan*/  wm8776_registers_init (struct oxygen*) ; 
 int /*<<< orphan*/  xonar_ds_handle_hp_jack (struct oxygen*) ; 
 int /*<<< orphan*/  xonar_enable_output (struct oxygen*) ; 

__attribute__((used)) static void xonar_ds_resume(struct oxygen *chip)
{
	wm8776_registers_init(chip);
	wm8766_registers_init(chip);
	xonar_enable_output(chip);
	xonar_ds_handle_hp_jack(chip);
}