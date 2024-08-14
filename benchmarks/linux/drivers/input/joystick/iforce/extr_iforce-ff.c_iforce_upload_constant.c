#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct resource {int /*<<< orphan*/  start; } ;
struct iforce_core_effect {int /*<<< orphan*/  flags; struct resource mod2_chunk; struct resource mod1_chunk; } ;
struct iforce {struct iforce_core_effect* core_effects; } ;
struct TYPE_10__ {int /*<<< orphan*/  interval; int /*<<< orphan*/  button; } ;
struct TYPE_9__ {int /*<<< orphan*/  delay; int /*<<< orphan*/  length; } ;
struct TYPE_6__ {int /*<<< orphan*/  fade_level; int /*<<< orphan*/  fade_length; int /*<<< orphan*/  attack_level; int /*<<< orphan*/  attack_length; } ;
struct TYPE_7__ {TYPE_1__ envelope; int /*<<< orphan*/  level; } ;
struct TYPE_8__ {TYPE_2__ constant; } ;
struct ff_effect {int id; int /*<<< orphan*/  direction; TYPE_5__ trigger; TYPE_4__ replay; TYPE_3__ u; } ;

/* Variables and functions */
 int /*<<< orphan*/  FF_MOD1_IS_USED ; 
 int /*<<< orphan*/  FF_MOD2_IS_USED ; 
 int make_core (struct iforce*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int make_envelope_modifier (struct iforce*,struct resource*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int make_magnitude_modifier (struct iforce*,struct resource*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ need_core (struct ff_effect*,struct ff_effect*) ; 
 scalar_t__ need_envelope_modifier (struct iforce*,struct ff_effect*,struct ff_effect*) ; 
 scalar_t__ need_magnitude_modifier (struct iforce*,struct ff_effect*,struct ff_effect*) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int iforce_upload_constant(struct iforce *iforce, struct ff_effect *effect, struct ff_effect *old)
{
	int core_id = effect->id;
	struct iforce_core_effect* core_effect = iforce->core_effects + core_id;
	struct resource* mod1_chunk = &(iforce->core_effects[core_id].mod1_chunk);
	struct resource* mod2_chunk = &(iforce->core_effects[core_id].mod2_chunk);
	int param1_err = 1;
	int param2_err = 1;
	int core_err = 0;

	if (!old || need_magnitude_modifier(iforce, old, effect)) {
		param1_err = make_magnitude_modifier(iforce, mod1_chunk,
			old != NULL,
			effect->u.constant.level);
		if (param1_err)
			return param1_err;
		set_bit(FF_MOD1_IS_USED, core_effect->flags);
	}

	if (!old || need_envelope_modifier(iforce, old, effect)) {
		param2_err = make_envelope_modifier(iforce, mod2_chunk,
			old != NULL,
			effect->u.constant.envelope.attack_length,
			effect->u.constant.envelope.attack_level,
			effect->u.constant.envelope.fade_length,
			effect->u.constant.envelope.fade_level);
		if (param2_err)
			return param2_err;
		set_bit(FF_MOD2_IS_USED, core_effect->flags);
	}

	if (!old || need_core(old, effect)) {
		core_err = make_core(iforce, effect->id,
			mod1_chunk->start,
			mod2_chunk->start,
			0x00,
			0x20,
			effect->replay.length,
			effect->replay.delay,
			effect->trigger.button,
			effect->trigger.interval,
			effect->direction);
	}

	/* If one of the parameter creation failed, we already returned an
	 * error code.
	 * If the core creation failed, we return its error code.
	 * Else: if one parameter at least was created, we return 0
	 *       else we return 1;
	 */
	return core_err < 0 ? core_err : (param1_err && param2_err);
}