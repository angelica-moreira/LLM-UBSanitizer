#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  soft; } ;
struct TYPE_6__ {TYPE_1__ state; } ;
struct TYPE_7__ {TYPE_2__ fpu; } ;
struct TYPE_8__ {TYPE_3__ thread; } ;

/* Variables and functions */
 TYPE_4__* current ; 
 int /*<<< orphan*/  fpstate_init_soft (int /*<<< orphan*/ *) ; 

void finit(void)
{
	fpstate_init_soft(&current->thread.fpu.state.soft);
}