#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_3__ {scalar_t__ mem_ptr; } ;
typedef  TYPE_1__ ips_ha_t ;

/* Variables and functions */
 scalar_t__ IPS_REG_I2O_OUTMSGQ ; 
 int /*<<< orphan*/  METHOD_TRACE (char*,int) ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 

__attribute__((used)) static uint32_t
ips_statupd_morpheus(ips_ha_t * ha)
{
	uint32_t val;

	METHOD_TRACE("ips_statupd_morpheus", 1);

	val = readl(ha->mem_ptr + IPS_REG_I2O_OUTMSGQ);

	return (val);
}