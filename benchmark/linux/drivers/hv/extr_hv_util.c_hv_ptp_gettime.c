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
struct timespec64 {int dummy; } ;
struct ptp_clock_info {int dummy; } ;

/* Variables and functions */
 struct timespec64 hv_get_adj_host_time () ; 

__attribute__((used)) static int hv_ptp_gettime(struct ptp_clock_info *info, struct timespec64 *ts)
{
	*ts = hv_get_adj_host_time();

	return 0;
}