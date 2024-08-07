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
struct gve_priv {int /*<<< orphan*/  service_task_flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  GVE_PRIV_FLAGS_PROBE_IN_PROGRESS ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void gve_clear_probe_in_progress(struct gve_priv *priv)
{
	clear_bit(GVE_PRIV_FLAGS_PROBE_IN_PROGRESS, &priv->service_task_flags);
}