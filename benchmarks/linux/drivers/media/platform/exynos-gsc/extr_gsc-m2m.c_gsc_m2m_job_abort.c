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
struct gsc_ctx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __gsc_m2m_job_abort (struct gsc_ctx*) ; 

__attribute__((used)) static void gsc_m2m_job_abort(void *priv)
{
	__gsc_m2m_job_abort((struct gsc_ctx *)priv);
}