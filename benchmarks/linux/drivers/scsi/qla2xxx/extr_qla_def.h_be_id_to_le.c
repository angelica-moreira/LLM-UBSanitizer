#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  al_pa; int /*<<< orphan*/  area; int /*<<< orphan*/  domain; } ;
typedef  TYPE_1__ le_id_t ;
struct TYPE_6__ {int /*<<< orphan*/  al_pa; int /*<<< orphan*/  area; int /*<<< orphan*/  domain; } ;
typedef  TYPE_2__ be_id_t ;

/* Variables and functions */

__attribute__((used)) static inline le_id_t be_id_to_le(be_id_t id)
{
	le_id_t res;

	res.domain = id.domain;
	res.area   = id.area;
	res.al_pa  = id.al_pa;

	return res;
}