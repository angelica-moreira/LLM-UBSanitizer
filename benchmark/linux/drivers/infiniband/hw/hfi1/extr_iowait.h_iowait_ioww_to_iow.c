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
struct iowait_work {struct iowait* iow; } ;
struct iowait {int dummy; } ;

/* Variables and functions */
 scalar_t__ likely (struct iowait_work*) ; 

__attribute__((used)) static inline struct iowait *iowait_ioww_to_iow(struct iowait_work *w)
{
	if (likely(w))
		return w->iow;
	return NULL;
}