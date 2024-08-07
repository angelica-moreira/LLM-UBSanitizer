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
struct ac97_controller {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pxa2xx_ac97_finish_reset () ; 
 int /*<<< orphan*/  pxa2xx_ac97_try_warm_reset () ; 

__attribute__((used)) static void pxa2xx_ac97_warm_reset(struct ac97_controller *adrv)
{
	pxa2xx_ac97_try_warm_reset();

	pxa2xx_ac97_finish_reset();
}