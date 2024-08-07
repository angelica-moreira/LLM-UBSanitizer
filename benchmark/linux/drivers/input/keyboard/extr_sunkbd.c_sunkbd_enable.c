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
struct sunkbd {int enabled; int /*<<< orphan*/  serio; } ;

/* Variables and functions */
 int /*<<< orphan*/  serio_continue_rx (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  serio_pause_rx (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sunkbd_enable(struct sunkbd *sunkbd, bool enable)
{
	serio_pause_rx(sunkbd->serio);
	sunkbd->enabled = enable;
	serio_continue_rx(sunkbd->serio);
}