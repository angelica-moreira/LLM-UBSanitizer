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
struct snd_rawmidi_substream {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dbg_hid (char*) ; 

__attribute__((used)) static int pcmidi_in_close(struct snd_rawmidi_substream *substream)
{
	dbg_hid("pcmidi in close\n");
	return 0;
}