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
struct bop_ring_buffer {scalar_t__ end; scalar_t__ begin; } ;

/* Variables and functions */

__attribute__((used)) static void brb_init(struct bop_ring_buffer *brb)
{
	brb->begin = 0;
	brb->end = 0;
}