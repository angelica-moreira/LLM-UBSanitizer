#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_kcontrol {struct isight* private_data; } ;
struct TYPE_3__ {scalar_t__* value; } ;
struct TYPE_4__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct isight {int dummy; } ;
typedef  scalar_t__ s32 ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  REG_GAIN ; 
 scalar_t__ be32_to_cpu (int /*<<< orphan*/ ) ; 
 int reg_read (struct isight*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int isight_gain_get(struct snd_kcontrol *ctl,
			   struct snd_ctl_elem_value *value)
{
	struct isight *isight = ctl->private_data;
	__be32 gain;
	int err;

	err = reg_read(isight, REG_GAIN, &gain);
	if (err < 0)
		return err;

	value->value.integer.value[0] = (s32)be32_to_cpu(gain);

	return 0;
}