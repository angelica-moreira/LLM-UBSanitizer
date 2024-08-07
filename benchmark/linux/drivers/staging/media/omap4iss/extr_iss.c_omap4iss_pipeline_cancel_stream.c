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
struct iss_pipeline {scalar_t__ output; scalar_t__ input; } ;

/* Variables and functions */
 int /*<<< orphan*/  omap4iss_video_cancel_stream (scalar_t__) ; 

void omap4iss_pipeline_cancel_stream(struct iss_pipeline *pipe)
{
	if (pipe->input)
		omap4iss_video_cancel_stream(pipe->input);
	if (pipe->output)
		omap4iss_video_cancel_stream(pipe->output);
}