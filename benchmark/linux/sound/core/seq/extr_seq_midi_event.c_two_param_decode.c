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
struct TYPE_3__ {int param; int value; } ;
struct TYPE_4__ {TYPE_1__ control; } ;
struct snd_seq_event {TYPE_2__ data; } ;

/* Variables and functions */

__attribute__((used)) static void two_param_decode(struct snd_seq_event *ev, unsigned char *buf)
{
	buf[0] = ev->data.control.param & 0x7f;
	buf[1] = ev->data.control.value & 0x7f;
}