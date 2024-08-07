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
struct cmp_connection {int /*<<< orphan*/  mutex; int /*<<< orphan*/  resources; } ;

/* Variables and functions */
 int /*<<< orphan*/  fw_iso_resources_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

void cmp_connection_release(struct cmp_connection *c)
{
	mutex_lock(&c->mutex);
	fw_iso_resources_free(&c->resources);
	mutex_unlock(&c->mutex);
}