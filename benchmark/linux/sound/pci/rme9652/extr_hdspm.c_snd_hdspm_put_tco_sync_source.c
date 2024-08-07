#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct snd_kcontrol {int dummy; } ;
struct TYPE_5__ {scalar_t__* item; } ;
struct TYPE_6__ {TYPE_2__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_3__ value; } ;
struct hdspm {TYPE_1__* tco; } ;
struct TYPE_4__ {scalar_t__ input; } ;

/* Variables and functions */
 int /*<<< orphan*/  hdspm_tco_write (struct hdspm*) ; 
 struct hdspm* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int snd_hdspm_put_tco_sync_source(struct snd_kcontrol *kcontrol,
					 struct snd_ctl_elem_value *ucontrol)
{
	struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);

	if (hdspm->tco->input != ucontrol->value.enumerated.item[0]) {
		hdspm->tco->input = ucontrol->value.enumerated.item[0];

		hdspm_tco_write(hdspm);

		return 1;
	}

	return 0;
}