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
struct pcmcia_device {int dummy; } ;

/* Variables and functions */
 int pcmcia_request_io (struct pcmcia_device*) ; 

__attribute__((used)) static int cm4000_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
	return pcmcia_request_io(p_dev);
}