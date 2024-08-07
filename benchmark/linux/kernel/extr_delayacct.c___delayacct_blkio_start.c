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
struct TYPE_4__ {TYPE_1__* delays; } ;
struct TYPE_3__ {int /*<<< orphan*/  blkio_start; } ;

/* Variables and functions */
 TYPE_2__* current ; 
 int /*<<< orphan*/  ktime_get_ns () ; 

void __delayacct_blkio_start(void)
{
	current->delays->blkio_start = ktime_get_ns();
}