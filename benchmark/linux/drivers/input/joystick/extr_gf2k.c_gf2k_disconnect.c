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
struct gf2k {int /*<<< orphan*/  dev; } ;
struct gameport {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  gameport_close (struct gameport*) ; 
 struct gf2k* gameport_get_drvdata (struct gameport*) ; 
 int /*<<< orphan*/  gameport_set_drvdata (struct gameport*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  input_unregister_device (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct gf2k*) ; 

__attribute__((used)) static void gf2k_disconnect(struct gameport *gameport)
{
	struct gf2k *gf2k = gameport_get_drvdata(gameport);

	input_unregister_device(gf2k->dev);
	gameport_close(gameport);
	gameport_set_drvdata(gameport, NULL);
	kfree(gf2k);
}