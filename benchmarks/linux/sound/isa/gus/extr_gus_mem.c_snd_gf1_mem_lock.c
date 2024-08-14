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
struct snd_gf1_mem {int /*<<< orphan*/  memory_mutex; } ;

/* Variables and functions */
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

void snd_gf1_mem_lock(struct snd_gf1_mem * alloc, int xup)
{
	if (!xup) {
		mutex_lock(&alloc->memory_mutex);
	} else {
		mutex_unlock(&alloc->memory_mutex);
	}
}