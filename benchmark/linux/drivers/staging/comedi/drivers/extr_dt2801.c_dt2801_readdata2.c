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
struct comedi_device {int dummy; } ;

/* Variables and functions */
 int dt2801_readdata (struct comedi_device*,int*) ; 

__attribute__((used)) static int dt2801_readdata2(struct comedi_device *dev, int *data)
{
	int lb = 0;
	int hb = 0;
	int ret;

	ret = dt2801_readdata(dev, &lb);
	if (ret)
		return ret;
	ret = dt2801_readdata(dev, &hb);
	if (ret)
		return ret;

	*data = (hb << 8) + lb;
	return 0;
}