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
struct amdtp_stream {size_t sfc; struct amdtp_dot* protocol; } ;
struct amdtp_dot {unsigned int* midi_fifo_used; } ;

/* Variables and functions */
 unsigned int* amdtp_rate_table ; 

__attribute__((used)) static inline void midi_use_bytes(struct amdtp_stream *s,
				  unsigned int port, unsigned int count)
{
	struct amdtp_dot *p = s->protocol;

	p->midi_fifo_used[port] += amdtp_rate_table[s->sfc] * count;
}