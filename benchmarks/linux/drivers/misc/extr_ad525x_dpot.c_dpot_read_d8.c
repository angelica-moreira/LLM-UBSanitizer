#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  client; TYPE_1__* bops; } ;
struct dpot_data {TYPE_2__ bdata; } ;
struct TYPE_3__ {int (* read_d8 ) (int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int stub1 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int dpot_read_d8(struct dpot_data *dpot)
{
	return dpot->bdata.bops->read_d8(dpot->bdata.client);
}