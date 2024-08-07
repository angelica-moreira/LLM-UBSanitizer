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
struct TYPE_2__ {int desc_count; int desc_avail; } ;
struct vnic_wq_copy {TYPE_1__ ring; } ;

/* Variables and functions */

__attribute__((used)) static inline unsigned int vnic_wq_copy_desc_in_use(struct vnic_wq_copy *wq)
{
	return wq->ring.desc_count - 1 - wq->ring.desc_avail;
}