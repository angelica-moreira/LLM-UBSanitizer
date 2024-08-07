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
struct wf_control {int dummy; } ;
struct smu_fan_control {scalar_t__ min; scalar_t__ max; int /*<<< orphan*/  reg; int /*<<< orphan*/  fan_type; scalar_t__ value; } ;
typedef  scalar_t__ s32 ;

/* Variables and functions */
 int smu_set_fan (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 struct smu_fan_control* to_smu_fan (struct wf_control*) ; 

__attribute__((used)) static int smu_fan_set(struct wf_control *ct, s32 value)
{
	struct smu_fan_control *fct = to_smu_fan(ct);

	if (value < fct->min)
		value = fct->min;
	if (value > fct->max)
		value = fct->max;
	fct->value = value;

	return smu_set_fan(fct->fan_type, fct->reg, value);
}