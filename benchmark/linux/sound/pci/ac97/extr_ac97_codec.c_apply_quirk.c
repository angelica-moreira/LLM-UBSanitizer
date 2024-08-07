#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_ac97 {int dummy; } ;
struct TYPE_3__ {int (* func ) (struct snd_ac97*) ;} ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 int EINVAL ; 
 TYPE_1__* applicable_quirks ; 
 int stub1 (struct snd_ac97*) ; 

__attribute__((used)) static int apply_quirk(struct snd_ac97 *ac97, int type)
{
	if (type <= 0)
		return 0;
	else if (type >= ARRAY_SIZE(applicable_quirks))
		return -EINVAL;
	if (applicable_quirks[type].func)
		return applicable_quirks[type].func(ac97);
	return 0;
}