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
struct pcmcia_device {int io_lines; TYPE_1__** resource; } ;
struct TYPE_2__ {int /*<<< orphan*/  flags; int /*<<< orphan*/  end; } ;

/* Variables and functions */
 int /*<<< orphan*/  FDOMAIN_REGION_SIZE ; 
 int /*<<< orphan*/  IO_DATA_PATH_WIDTH ; 
 int /*<<< orphan*/  IO_DATA_PATH_WIDTH_AUTO ; 
 int pcmcia_request_io (struct pcmcia_device*) ; 

__attribute__((used)) static int fdomain_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
	p_dev->io_lines = 10;
	p_dev->resource[0]->end = FDOMAIN_REGION_SIZE;
	p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
	p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
	return pcmcia_request_io(p_dev);
}