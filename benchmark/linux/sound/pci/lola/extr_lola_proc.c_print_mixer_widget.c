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
struct snd_info_buffer {int dummy; } ;
struct lola {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  LOLA_PAR_AUDIO_WIDGET_CAP ; 
 int /*<<< orphan*/  lola_read_param (struct lola*,int,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  snd_iprintf (struct snd_info_buffer*,char*,int,unsigned int) ; 

__attribute__((used)) static void print_mixer_widget(struct snd_info_buffer *buffer,
			       struct lola *chip, int nid)
{
	unsigned int val;

	lola_read_param(chip, nid, LOLA_PAR_AUDIO_WIDGET_CAP, &val);
	snd_iprintf(buffer, "Node 0x%02x [Mixer] wcaps 0x%x\n", nid, val);
}