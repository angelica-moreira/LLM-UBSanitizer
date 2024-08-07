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
struct riva_par {TYPE_1__* chan; } ;
struct TYPE_2__ {int /*<<< orphan*/ * par; int /*<<< orphan*/  adapter; } ;

/* Variables and functions */
 int /*<<< orphan*/  i2c_del_adapter (int /*<<< orphan*/ *) ; 

void riva_delete_i2c_busses(struct riva_par *par)
{
	int i;

	for (i = 0; i < 3; i++) {
		if (!par->chan[i].par)
			continue;
		i2c_del_adapter(&par->chan[i].adapter);
		par->chan[i].par = NULL;
	}
}