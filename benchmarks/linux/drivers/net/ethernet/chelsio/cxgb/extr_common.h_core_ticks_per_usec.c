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
typedef  int /*<<< orphan*/  adapter_t ;
struct TYPE_2__ {int clock_core; } ;

/* Variables and functions */
 TYPE_1__* board_info (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static inline unsigned int core_ticks_per_usec(const adapter_t *adap)
{
	return board_info(adap)->clock_core / 1000000;
}