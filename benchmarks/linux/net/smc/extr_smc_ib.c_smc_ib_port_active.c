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
typedef  int u8 ;
struct smc_ib_device {TYPE_1__* pattr; } ;
struct TYPE_2__ {scalar_t__ state; } ;

/* Variables and functions */
 scalar_t__ IB_PORT_ACTIVE ; 

bool smc_ib_port_active(struct smc_ib_device *smcibdev, u8 ibport)
{
	return smcibdev->pattr[ibport - 1].state == IB_PORT_ACTIVE;
}