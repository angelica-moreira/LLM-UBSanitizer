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
 int /*<<< orphan*/  debug_event (int /*<<< orphan*/ ,int,void*,int) ; 
 int /*<<< orphan*/  vfio_ccw_debug_trace_id ; 

__attribute__((used)) static inline void VFIO_CCW_HEX_EVENT(int level, void *data, int length)
{
	debug_event(vfio_ccw_debug_trace_id, level, data, length);
}