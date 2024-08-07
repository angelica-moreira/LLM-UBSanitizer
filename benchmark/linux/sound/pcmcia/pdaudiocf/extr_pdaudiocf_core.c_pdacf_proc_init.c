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
struct snd_pdacf {int /*<<< orphan*/  card; } ;

/* Variables and functions */
 int /*<<< orphan*/  pdacf_proc_read ; 
 int /*<<< orphan*/  snd_card_ro_proc_new (int /*<<< orphan*/ ,char*,struct snd_pdacf*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pdacf_proc_init(struct snd_pdacf *chip)
{
	snd_card_ro_proc_new(chip->card, "pdaudiocf", chip, pdacf_proc_read);
}