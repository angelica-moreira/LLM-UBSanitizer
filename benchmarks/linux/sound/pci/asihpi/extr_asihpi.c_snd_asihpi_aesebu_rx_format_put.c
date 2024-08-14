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
struct snd_kcontrol {int dummy; } ;
struct snd_ctl_elem_value {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  hpi_aesebu_receiver_set_format ; 
 int snd_asihpi_aesebu_format_put (struct snd_kcontrol*,struct snd_ctl_elem_value*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int snd_asihpi_aesebu_rx_format_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol) {
	return snd_asihpi_aesebu_format_put(kcontrol, ucontrol,
					hpi_aesebu_receiver_set_format);
}