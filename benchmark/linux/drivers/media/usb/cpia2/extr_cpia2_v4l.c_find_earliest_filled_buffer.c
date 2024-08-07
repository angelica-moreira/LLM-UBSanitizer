#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct camera_data {int num_frames; TYPE_1__* buffers; } ;
struct TYPE_2__ {scalar_t__ status; scalar_t__ ts; } ;

/* Variables and functions */
 scalar_t__ FRAME_READY ; 

__attribute__((used)) static int find_earliest_filled_buffer(struct camera_data *cam)
{
	int i;
	int found = -1;
	for (i=0; i<cam->num_frames; i++) {
		if(cam->buffers[i].status == FRAME_READY) {
			if(found < 0) {
				found = i;
			} else {
				/* find which buffer is earlier */
				if (cam->buffers[i].ts < cam->buffers[found].ts)
					found = i;
			}
		}
	}
	return found;
}