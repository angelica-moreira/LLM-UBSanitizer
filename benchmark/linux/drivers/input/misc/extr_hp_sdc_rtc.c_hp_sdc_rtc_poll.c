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
struct file {int dummy; } ;
typedef  int /*<<< orphan*/  poll_table ;
typedef  int __poll_t ;

/* Variables and functions */
 int EPOLLIN ; 
 int EPOLLRDNORM ; 

__attribute__((used)) static __poll_t hp_sdc_rtc_poll(struct file *file, poll_table *wait)
{
        unsigned long l;

	l = 0;
        if (l != 0)
                return EPOLLIN | EPOLLRDNORM;
        return 0;
}