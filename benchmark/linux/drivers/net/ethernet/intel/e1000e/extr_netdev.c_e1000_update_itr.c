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
typedef  unsigned int u16 ;

/* Variables and functions */
#define  bulk_latency 130 
#define  low_latency 129 
#define  lowest_latency 128 

__attribute__((used)) static unsigned int e1000_update_itr(u16 itr_setting, int packets, int bytes)
{
	unsigned int retval = itr_setting;

	if (packets == 0)
		return itr_setting;

	switch (itr_setting) {
	case lowest_latency:
		/* handle TSO and jumbo frames */
		if (bytes / packets > 8000)
			retval = bulk_latency;
		else if ((packets < 5) && (bytes > 512))
			retval = low_latency;
		break;
	case low_latency:	/* 50 usec aka 20000 ints/s */
		if (bytes > 10000) {
			/* this if handles the TSO accounting */
			if (bytes / packets > 8000)
				retval = bulk_latency;
			else if ((packets < 10) || ((bytes / packets) > 1200))
				retval = bulk_latency;
			else if ((packets > 35))
				retval = lowest_latency;
		} else if (bytes / packets > 2000) {
			retval = bulk_latency;
		} else if (packets <= 2 && bytes < 512) {
			retval = lowest_latency;
		}
		break;
	case bulk_latency:	/* 250 usec aka 4000 ints/s */
		if (bytes > 25000) {
			if (packets > 35)
				retval = low_latency;
		} else if (bytes < 6000) {
			retval = low_latency;
		}
		break;
	}

	return retval;
}