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
struct wil_status_ring {int elem_size; int swhead; scalar_t__ va; } ;
struct wil_rx_status_compressed {scalar_t__ buff_id; } ;

/* Variables and functions */

__attribute__((used)) static inline void wil_rx_status_reset_buff_id(struct wil_status_ring *s)
{
	((struct wil_rx_status_compressed *)
		(s->va + (s->elem_size * s->swhead)))->buff_id = 0;
}