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
struct gameport {struct a3d* port_data; } ;
struct a3d {int /*<<< orphan*/  gameport; } ;

/* Variables and functions */
 int /*<<< orphan*/  gameport_stop_polling (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void a3d_adc_close(struct gameport *gameport)
{
	struct a3d *a3d = gameport->port_data;

	gameport_stop_polling(a3d->gameport);
}