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
struct hisi_thermal_sensor {struct hisi_thermal_data* data; } ;
struct hisi_thermal_data {int /*<<< orphan*/  regs; } ;

/* Variables and functions */
 int hi6220_thermal_get_temperature (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int hi6220_thermal_get_temp(struct hisi_thermal_sensor *sensor)
{
	struct hisi_thermal_data *data = sensor->data;

	return hi6220_thermal_get_temperature(data->regs);
}