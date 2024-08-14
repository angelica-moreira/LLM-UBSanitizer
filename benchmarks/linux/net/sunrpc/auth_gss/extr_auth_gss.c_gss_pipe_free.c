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
struct gss_pipe {int /*<<< orphan*/  kref; } ;

/* Variables and functions */
 int /*<<< orphan*/  __gss_pipe_release ; 
 int /*<<< orphan*/  kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void gss_pipe_free(struct gss_pipe *p)
{
	if (p != NULL)
		kref_put(&p->kref, __gss_pipe_release);
}