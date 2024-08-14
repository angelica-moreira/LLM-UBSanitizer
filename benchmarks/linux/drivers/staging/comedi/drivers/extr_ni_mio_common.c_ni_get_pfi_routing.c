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
struct ni_private {scalar_t__ is_m_series; } ;
struct comedi_device {struct ni_private* private; } ;

/* Variables and functions */
 unsigned int NI_PFI (int /*<<< orphan*/ ) ; 
 unsigned int ni_m_series_get_pfi_routing (struct comedi_device*,unsigned int) ; 
 unsigned int ni_old_get_pfi_routing (struct comedi_device*,unsigned int) ; 

__attribute__((used)) static unsigned int ni_get_pfi_routing(struct comedi_device *dev,
				       unsigned int chan)
{
	struct ni_private *devpriv = dev->private;

	if (chan >= NI_PFI(0)) {
		/* allow new and old names of pfi channels to work. */
		chan -= NI_PFI(0);
	}
	return (devpriv->is_m_series)
			? ni_m_series_get_pfi_routing(dev, chan)
			: ni_old_get_pfi_routing(dev, chan);
}