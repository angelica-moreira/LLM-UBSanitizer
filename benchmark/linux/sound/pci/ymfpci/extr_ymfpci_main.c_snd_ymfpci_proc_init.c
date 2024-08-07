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
struct snd_ymfpci {int dummy; } ;
struct snd_card {int dummy; } ;

/* Variables and functions */
 int snd_card_ro_proc_new (struct snd_card*,char*,struct snd_ymfpci*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ymfpci_proc_read ; 

__attribute__((used)) static int snd_ymfpci_proc_init(struct snd_card *card, struct snd_ymfpci *chip)
{
	return snd_card_ro_proc_new(card, "ymfpci", chip, snd_ymfpci_proc_read);
}