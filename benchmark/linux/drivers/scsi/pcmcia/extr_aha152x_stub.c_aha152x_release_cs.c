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
struct pcmcia_device {TYPE_1__* priv; } ;
struct TYPE_2__ {int /*<<< orphan*/  host; } ;
typedef  TYPE_1__ scsi_info_t ;

/* Variables and functions */
 int /*<<< orphan*/  aha152x_release (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcmcia_disable_device (struct pcmcia_device*) ; 

__attribute__((used)) static void aha152x_release_cs(struct pcmcia_device *link)
{
	scsi_info_t *info = link->priv;

	aha152x_release(info->host);
	pcmcia_disable_device(link);
}