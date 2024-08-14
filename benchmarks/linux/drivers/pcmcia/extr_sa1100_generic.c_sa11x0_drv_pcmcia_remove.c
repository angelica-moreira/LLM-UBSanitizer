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
struct soc_pcmcia_socket {int dummy; } ;
struct platform_device {int id; } ;

/* Variables and functions */
 struct soc_pcmcia_socket* platform_get_drvdata (struct platform_device*) ; 
 int sa11x0_drv_pcmcia_legacy_remove (struct platform_device*) ; 
 int /*<<< orphan*/  soc_pcmcia_remove_one (struct soc_pcmcia_socket*) ; 

__attribute__((used)) static int sa11x0_drv_pcmcia_remove(struct platform_device *dev)
{
	struct soc_pcmcia_socket *skt;

	if (dev->id == -1)
		return sa11x0_drv_pcmcia_legacy_remove(dev);

	skt = platform_get_drvdata(dev);

	soc_pcmcia_remove_one(skt);

	return 0;
}