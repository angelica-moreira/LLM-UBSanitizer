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
struct snd_i2c_device {TYPE_2__* bus; } ;
struct TYPE_4__ {TYPE_1__* ops; } ;
struct TYPE_3__ {int (* sendbytes ) (struct snd_i2c_device*,unsigned char*,int) ;} ;

/* Variables and functions */
 int stub1 (struct snd_i2c_device*,unsigned char*,int) ; 

int snd_i2c_sendbytes(struct snd_i2c_device *device, unsigned char *bytes, int count)
{
	return device->bus->ops->sendbytes(device, bytes, count);
}