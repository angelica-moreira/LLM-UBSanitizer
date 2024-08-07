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
 int EINVAL ; 
 int EOVERFLOW ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 int alloc_callchain_buffers () ; 
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 int atomic_inc_return (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  callchain_mutex ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nr_callchain_events ; 
 int sysctl_perf_event_max_stack ; 

int get_callchain_buffers(int event_max_stack)
{
	int err = 0;
	int count;

	mutex_lock(&callchain_mutex);

	count = atomic_inc_return(&nr_callchain_events);
	if (WARN_ON_ONCE(count < 1)) {
		err = -EINVAL;
		goto exit;
	}

	/*
	 * If requesting per event more than the global cap,
	 * return a different error to help userspace figure
	 * this out.
	 *
	 * And also do it here so that we have &callchain_mutex held.
	 */
	if (event_max_stack > sysctl_perf_event_max_stack) {
		err = -EOVERFLOW;
		goto exit;
	}

	if (count == 1)
		err = alloc_callchain_buffers();
exit:
	if (err)
		atomic_dec(&nr_callchain_events);

	mutex_unlock(&callchain_mutex);

	return err;
}