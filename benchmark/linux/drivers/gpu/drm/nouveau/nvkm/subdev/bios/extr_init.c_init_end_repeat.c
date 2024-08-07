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
struct nvbios_init {scalar_t__ offset; scalar_t__ repend; scalar_t__ repeat; } ;

/* Variables and functions */
 int /*<<< orphan*/  trace (char*) ; 

__attribute__((used)) static void
init_end_repeat(struct nvbios_init *init)
{
	trace("END_REPEAT\n");
	init->offset += 1;

	if (init->repeat) {
		init->repend = init->offset;
		init->offset = 0;
	}
}