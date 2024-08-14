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
struct midi_buffer {int pos_read; int size; scalar_t__ full; } ;

/* Variables and functions */
 int line6_midibuf_bytes_used (struct midi_buffer*) ; 

int line6_midibuf_ignore(struct midi_buffer *this, int length)
{
	int bytes_used = line6_midibuf_bytes_used(this);

	if (length > bytes_used)
		length = bytes_used;

	this->pos_read = (this->pos_read + length) % this->size;
	this->full = 0;
	return length;
}