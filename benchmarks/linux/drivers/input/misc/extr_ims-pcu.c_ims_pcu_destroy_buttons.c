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
struct ims_pcu_buttons {int /*<<< orphan*/  input; } ;
struct ims_pcu {struct ims_pcu_buttons buttons; } ;

/* Variables and functions */
 int /*<<< orphan*/  input_unregister_device (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ims_pcu_destroy_buttons(struct ims_pcu *pcu)
{
	struct ims_pcu_buttons *buttons = &pcu->buttons;

	input_unregister_device(buttons->input);
}