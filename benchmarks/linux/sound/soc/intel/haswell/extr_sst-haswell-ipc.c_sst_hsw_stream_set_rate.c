#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int frequency; } ;
struct TYPE_4__ {TYPE_1__ format; } ;
struct sst_hsw_stream {TYPE_2__ request; scalar_t__ commited; } ;
struct sst_hsw {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*) ; 

int sst_hsw_stream_set_rate(struct sst_hsw *hsw,
	struct sst_hsw_stream *stream, int rate)
{
	if (stream->commited) {
		dev_err(hsw->dev, "error: stream committed for set rate\n");
		return -EINVAL;
	}

	stream->request.format.frequency = rate;
	return 0;
}