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
struct vhost_virtqueue {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  vhost_init_is_le (struct vhost_virtqueue*) ; 

__attribute__((used)) static void vhost_reset_is_le(struct vhost_virtqueue *vq)
{
	vhost_init_is_le(vq);
}