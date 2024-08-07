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
struct i915_request {struct i915_capture_list* capture_list; } ;
struct i915_capture_list {struct i915_capture_list* next; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct i915_capture_list*) ; 

__attribute__((used)) static void free_capture_list(struct i915_request *request)
{
	struct i915_capture_list *capture;

	capture = request->capture_list;
	while (capture) {
		struct i915_capture_list *next = capture->next;

		kfree(capture);
		capture = next;
	}
}