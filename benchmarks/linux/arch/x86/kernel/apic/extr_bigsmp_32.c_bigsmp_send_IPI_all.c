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

/* Variables and functions */
 int /*<<< orphan*/  cpu_online_mask ; 
 int /*<<< orphan*/  default_send_IPI_mask_sequence_phys (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void bigsmp_send_IPI_all(int vector)
{
	default_send_IPI_mask_sequence_phys(cpu_online_mask, vector);
}