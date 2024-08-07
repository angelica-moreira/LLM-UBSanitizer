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
struct vio_driver_state {TYPE_1__* ops; } ;
struct TYPE_2__ {int (* send_attr ) (struct vio_driver_state*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int stub1 (struct vio_driver_state*) ; 

__attribute__((used)) static int send_attr(struct vio_driver_state *vio)
{
	if (!vio->ops)
		return -EINVAL;

	return vio->ops->send_attr(vio);
}