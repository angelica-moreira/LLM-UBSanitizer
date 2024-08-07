#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  count; int /*<<< orphan*/ * list; } ;
struct wm8524_priv {int /*<<< orphan*/ * rate_constraint_list; TYPE_1__ rate_constraint; } ;
struct snd_soc_component {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 struct wm8524_priv* snd_soc_component_get_drvdata (struct snd_soc_component*) ; 

__attribute__((used)) static int wm8524_probe(struct snd_soc_component *component)
{
	struct wm8524_priv *wm8524 = snd_soc_component_get_drvdata(component);

	wm8524->rate_constraint.list = &wm8524->rate_constraint_list[0];
	wm8524->rate_constraint.count =
		ARRAY_SIZE(wm8524->rate_constraint_list);

	return 0;
}