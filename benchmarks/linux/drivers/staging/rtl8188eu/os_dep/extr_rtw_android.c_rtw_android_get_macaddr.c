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
struct net_device {int /*<<< orphan*/  dev_addr; } ;

/* Variables and functions */
 int snprintf (char*,int,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rtw_android_get_macaddr(struct net_device *net, char *command,
				   int total_len)
{
	return snprintf(command, total_len, "Macaddr = %pM",
				 net->dev_addr);
}