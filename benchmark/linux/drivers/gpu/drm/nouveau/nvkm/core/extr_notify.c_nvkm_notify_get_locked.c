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
struct nvkm_notify {scalar_t__ block; int /*<<< orphan*/  index; int /*<<< orphan*/  types; int /*<<< orphan*/  event; } ;

/* Variables and functions */
 int /*<<< orphan*/  nvkm_event_get (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
nvkm_notify_get_locked(struct nvkm_notify *notify)
{
	if (--notify->block == 0)
		nvkm_event_get(notify->event, notify->types, notify->index);
}