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
struct net_device {int dummy; } ;
struct i2400m {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  d_fnend (int,struct device*,char*,struct net_device*,struct i2400m*) ; 
 int /*<<< orphan*/  d_fnstart (int,struct device*,char*,struct net_device*,struct i2400m*) ; 
 struct device* i2400m_dev (struct i2400m*) ; 
 int /*<<< orphan*/  i2400m_net_wake_stop (struct i2400m*) ; 
 struct i2400m* net_dev_to_i2400m (struct net_device*) ; 

__attribute__((used)) static
int i2400m_stop(struct net_device *net_dev)
{
	struct i2400m *i2400m = net_dev_to_i2400m(net_dev);
	struct device *dev = i2400m_dev(i2400m);

	d_fnstart(3, dev, "(net_dev %p [i2400m %p])\n", net_dev, i2400m);
	i2400m_net_wake_stop(i2400m);
	d_fnend(3, dev, "(net_dev %p [i2400m %p]) = 0\n", net_dev, i2400m);
	return 0;
}