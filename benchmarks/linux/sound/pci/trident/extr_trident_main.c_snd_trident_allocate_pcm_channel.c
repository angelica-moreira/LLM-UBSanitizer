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
struct snd_trident {scalar_t__ ChanPCMcnt; scalar_t__ ChanPCM; int* ChanMap; } ;

/* Variables and functions */
 size_t T4D_BANK_B ; 

__attribute__((used)) static int snd_trident_allocate_pcm_channel(struct snd_trident * trident)
{
	int idx;

	if (trident->ChanPCMcnt >= trident->ChanPCM)
		return -1;
	for (idx = 31; idx >= 0; idx--) {
		if (!(trident->ChanMap[T4D_BANK_B] & (1 << idx))) {
			trident->ChanMap[T4D_BANK_B] |= 1 << idx;
			trident->ChanPCMcnt++;
			return idx + 32;
		}
	}
	return -1;
}