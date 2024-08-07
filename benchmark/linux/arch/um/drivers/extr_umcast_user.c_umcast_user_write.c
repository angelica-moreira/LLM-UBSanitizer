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
struct umcast_data {struct sockaddr_in* remote_addr; } ;
struct sockaddr_in {int dummy; } ;

/* Variables and functions */
 int net_sendto (int,void*,int,struct sockaddr_in*,int) ; 

int umcast_user_write(int fd, void *buf, int len, struct umcast_data *pri)
{
	struct sockaddr_in *data_addr = pri->remote_addr;

	return net_sendto(fd, buf, len, data_addr, sizeof(*data_addr));
}