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
struct fq_flow {int /*<<< orphan*/ * next; } ;

/* Variables and functions */
 int /*<<< orphan*/  detached ; 

__attribute__((used)) static bool fq_flow_is_detached(const struct fq_flow *f)
{
	return f->next == &detached;
}