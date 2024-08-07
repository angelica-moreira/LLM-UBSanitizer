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
typedef  size_t uint8_t ;
struct dc_stream_status {int dummy; } ;
struct dc_stream_state {int dummy; } ;
struct dc_state {size_t stream_count; struct dc_stream_status* stream_status; struct dc_stream_state** streams; } ;

/* Variables and functions */

struct dc_stream_status *dc_stream_get_status_from_state(
	struct dc_state *state,
	struct dc_stream_state *stream)
{
	uint8_t i;

	for (i = 0; i < state->stream_count; i++) {
		if (stream == state->streams[i])
			return &state->stream_status[i];
	}

	return NULL;
}