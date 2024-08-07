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
struct ngene_channel {scalar_t__ users; int /*<<< orphan*/  running; TYPE_1__* dev; } ;
struct dvb_demux_feed {struct dvb_demux* demux; } ;
struct dvb_demux {struct ngene_channel* priv; } ;
struct TYPE_2__ {int /*<<< orphan*/  cmd_timeout_workaround; } ;

/* Variables and functions */
 int /*<<< orphan*/  set_transfer (struct ngene_channel*,int) ; 

int ngene_start_feed(struct dvb_demux_feed *dvbdmxfeed)
{
	struct dvb_demux *dvbdmx = dvbdmxfeed->demux;
	struct ngene_channel *chan = dvbdmx->priv;

	if (chan->users == 0) {
		if (!chan->dev->cmd_timeout_workaround || !chan->running)
			set_transfer(chan, 1);
	}

	return ++chan->users;
}