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
struct orinoco_private {struct orinoco_pccard* card; } ;
struct orinoco_pccard {struct pcmcia_device* p_dev; } ;

/* Variables and functions */
 int spectrum_reset (struct pcmcia_device*,int) ; 

__attribute__((used)) static int
spectrum_cs_stop_firmware(struct orinoco_private *priv, int idle)
{
	struct orinoco_pccard *card = priv->card;
	struct pcmcia_device *link = card->p_dev;

	return spectrum_reset(link, idle);
}