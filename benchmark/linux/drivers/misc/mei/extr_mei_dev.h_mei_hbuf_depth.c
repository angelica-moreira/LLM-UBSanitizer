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
typedef  int /*<<< orphan*/  u32 ;
struct mei_device {TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* hbuf_depth ) (struct mei_device const*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct mei_device const*) ; 

__attribute__((used)) static inline u32 mei_hbuf_depth(const struct mei_device *dev)
{
	return dev->ops->hbuf_depth(dev);
}