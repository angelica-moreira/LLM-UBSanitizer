#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {void (* mask ) (unsigned int) ;} ;

/* Variables and functions */
 TYPE_1__* evtchn_ops ; 
 void stub1 (unsigned int) ; 

__attribute__((used)) static inline void mask_evtchn(unsigned port)
{
	return evtchn_ops->mask(port);
}