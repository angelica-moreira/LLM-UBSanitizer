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
struct mddev {int dummy; } ;

/* Variables and functions */
 int mddev_congested (struct mddev*,int) ; 

__attribute__((used)) static int md_congested(void *data, int bits)
{
	struct mddev *mddev = data;
	return mddev_congested(mddev, bits);
}