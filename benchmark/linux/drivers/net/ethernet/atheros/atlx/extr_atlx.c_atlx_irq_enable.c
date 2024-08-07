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
struct atlx_adapter {int int_enabled; } ;

/* Variables and functions */
 int /*<<< orphan*/  IMR_NORMAL_MASK ; 
 int /*<<< orphan*/  atlx_imr_set (struct atlx_adapter*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void atlx_irq_enable(struct atlx_adapter *adapter)
{
	atlx_imr_set(adapter, IMR_NORMAL_MASK);
	adapter->int_enabled = true;
}