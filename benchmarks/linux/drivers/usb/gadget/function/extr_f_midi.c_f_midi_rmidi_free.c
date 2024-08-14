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
struct snd_rawmidi {int /*<<< orphan*/  private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  f_midi_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void f_midi_rmidi_free(struct snd_rawmidi *rmidi)
{
	f_midi_free(rmidi->private_data);
}