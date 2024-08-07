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
struct efx_filter_spec {int priority; int flags; unsigned int dmaq_id; scalar_t__ rss_context; } ;
typedef  enum efx_filter_priority { ____Placeholder_efx_filter_priority } efx_filter_priority ;
typedef  enum efx_filter_flags { ____Placeholder_efx_filter_flags } efx_filter_flags ;

/* Variables and functions */
 int EFX_FILTER_FLAG_RX ; 
 int /*<<< orphan*/  memset (struct efx_filter_spec*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void efx_filter_init_rx(struct efx_filter_spec *spec,
				      enum efx_filter_priority priority,
				      enum efx_filter_flags flags,
				      unsigned rxq_id)
{
	memset(spec, 0, sizeof(*spec));
	spec->priority = priority;
	spec->flags = EFX_FILTER_FLAG_RX | flags;
	spec->rss_context = 0;
	spec->dmaq_id = rxq_id;
}