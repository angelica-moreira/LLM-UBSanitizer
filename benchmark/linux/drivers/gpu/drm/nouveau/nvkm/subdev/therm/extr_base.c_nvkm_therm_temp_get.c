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
struct nvkm_therm {TYPE_1__* func; } ;
struct TYPE_2__ {int (* temp_get ) (struct nvkm_therm*) ;} ;

/* Variables and functions */
 int ENODEV ; 
 int stub1 (struct nvkm_therm*) ; 

int
nvkm_therm_temp_get(struct nvkm_therm *therm)
{
	if (therm->func->temp_get)
		return therm->func->temp_get(therm);
	return -ENODEV;
}