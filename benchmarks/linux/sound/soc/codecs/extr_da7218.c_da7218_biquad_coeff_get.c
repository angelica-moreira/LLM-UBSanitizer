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
struct soc_bytes_ext {int max; } ;
struct snd_soc_component {int dummy; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_3__ {int /*<<< orphan*/  data; } ;
struct TYPE_4__ {TYPE_1__ bytes; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct da7218_priv {int /*<<< orphan*/  stbiq_3stage_coeff; int /*<<< orphan*/  biq_5stage_coeff; } ;

/* Variables and functions */
#define  DA7218_OUT_1_BIQ_5STAGE_CFG_SIZE 129 
#define  DA7218_SIDETONE_BIQ_3STAGE_CFG_SIZE 128 
 int EINVAL ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct da7218_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 
 struct snd_soc_component* snd_soc_kcontrol_component (struct snd_kcontrol*) ; 

__attribute__((used)) static int da7218_biquad_coeff_get(struct snd_kcontrol *kcontrol,
				   struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_component *component = snd_soc_kcontrol_component(kcontrol);
	struct da7218_priv *da7218 = snd_soc_component_get_drvdata(component);
	struct soc_bytes_ext *bytes_ext =
		(struct soc_bytes_ext *) kcontrol->private_value;

	/* Determine which BiQuads we're setting based on size of config data */
	switch (bytes_ext->max) {
	case DA7218_OUT_1_BIQ_5STAGE_CFG_SIZE:
		memcpy(ucontrol->value.bytes.data, da7218->biq_5stage_coeff,
		       bytes_ext->max);
		break;
	case DA7218_SIDETONE_BIQ_3STAGE_CFG_SIZE:
		memcpy(ucontrol->value.bytes.data, da7218->stbiq_3stage_coeff,
		       bytes_ext->max);
		break;
	default:
		return -EINVAL;
	}

	return 0;
}