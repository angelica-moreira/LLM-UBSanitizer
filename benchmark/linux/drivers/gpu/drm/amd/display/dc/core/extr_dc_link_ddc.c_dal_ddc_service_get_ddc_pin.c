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
struct ddc_service {struct ddc* ddc_pin; } ;
struct ddc {int dummy; } ;

/* Variables and functions */

struct ddc *dal_ddc_service_get_ddc_pin(struct ddc_service *ddc_service)
{
	return ddc_service->ddc_pin;
}