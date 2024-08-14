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
struct menelaus_chip {int /*<<< orphan*/  work; } ;
struct i2c_client {int /*<<< orphan*/  irq; } ;

/* Variables and functions */
 int /*<<< orphan*/  flush_work (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct menelaus_chip*) ; 
 struct menelaus_chip* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/ * the_menelaus ; 

__attribute__((used)) static int menelaus_remove(struct i2c_client *client)
{
	struct menelaus_chip	*menelaus = i2c_get_clientdata(client);

	free_irq(client->irq, menelaus);
	flush_work(&menelaus->work);
	the_menelaus = NULL;
	return 0;
}