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
struct net_bridge {int stp_enabled; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 struct net_bridge* to_bridge (struct device*) ; 

__attribute__((used)) static ssize_t stp_state_show(struct device *d,
			      struct device_attribute *attr, char *buf)
{
	struct net_bridge *br = to_bridge(d);
	return sprintf(buf, "%d\n", br->stp_enabled);
}