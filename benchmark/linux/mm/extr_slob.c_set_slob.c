#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int slobidx_t ;
struct TYPE_4__ {int units; } ;
typedef  TYPE_1__ slob_t ;

/* Variables and functions */
 unsigned long PAGE_MASK ; 

__attribute__((used)) static void set_slob(slob_t *s, slobidx_t size, slob_t *next)
{
	slob_t *base = (slob_t *)((unsigned long)s & PAGE_MASK);
	slobidx_t offset = next - base;

	if (size > 1) {
		s[0].units = size;
		s[1].units = offset;
	} else
		s[0].units = -offset;
}