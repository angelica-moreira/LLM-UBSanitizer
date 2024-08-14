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
struct eventfd_ctx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  eventfd_ctx_put (struct eventfd_ctx*) ; 

__attribute__((used)) static void irq_free(void *private)
{
	struct eventfd_ctx *ev_ctx = private;

	eventfd_ctx_put(ev_ctx);
}