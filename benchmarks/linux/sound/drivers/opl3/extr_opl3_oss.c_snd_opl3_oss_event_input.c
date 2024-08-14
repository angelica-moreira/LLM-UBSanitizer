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
struct snd_seq_event {scalar_t__ type; } ;
struct snd_opl3 {int /*<<< orphan*/  oss_chset; } ;

/* Variables and functions */
 scalar_t__ SNDRV_SEQ_EVENT_OSS ; 
 int /*<<< orphan*/  opl3_ops ; 
 int /*<<< orphan*/  snd_midi_process_event (int /*<<< orphan*/ *,struct snd_seq_event*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int snd_opl3_oss_event_input(struct snd_seq_event *ev, int direct,
				    void *private_data, int atomic, int hop)
{
	struct snd_opl3 *opl3 = private_data;

	if (ev->type != SNDRV_SEQ_EVENT_OSS)
		snd_midi_process_event(&opl3_ops, ev, opl3->oss_chset);
	return 0;
}