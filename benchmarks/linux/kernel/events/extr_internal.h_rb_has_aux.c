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
struct ring_buffer {int /*<<< orphan*/  aux_nr_pages; } ;

/* Variables and functions */

__attribute__((used)) static inline bool rb_has_aux(struct ring_buffer *rb)
{
	return !!rb->aux_nr_pages;
}