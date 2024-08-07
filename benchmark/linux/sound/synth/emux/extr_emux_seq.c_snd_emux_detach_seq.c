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
struct snd_emux {int client; scalar_t__ voices; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_emux_terminate_all (struct snd_emux*) ; 
 int /*<<< orphan*/  snd_seq_delete_kernel_client (int) ; 

void
snd_emux_detach_seq(struct snd_emux *emu)
{
	if (emu->voices)
		snd_emux_terminate_all(emu);
		
	if (emu->client >= 0) {
		snd_seq_delete_kernel_client(emu->client);
		emu->client = -1;
	}
}