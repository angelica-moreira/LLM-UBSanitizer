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
struct softnet_data {int /*<<< orphan*/  csd; int /*<<< orphan*/  cpu; struct softnet_data* rps_ipi_next; } ;

/* Variables and functions */
 scalar_t__ cpu_online (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smp_call_function_single_async (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void net_rps_send_ipi(struct softnet_data *remsd)
{
#ifdef CONFIG_RPS
	while (remsd) {
		struct softnet_data *next = remsd->rps_ipi_next;

		if (cpu_online(remsd->cpu))
			smp_call_function_single_async(remsd->cpu, &remsd->csd);
		remsd = next;
	}
#endif
}