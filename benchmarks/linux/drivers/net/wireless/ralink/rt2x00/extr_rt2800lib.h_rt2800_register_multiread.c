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
struct rt2x00_dev {TYPE_1__* ops; } ;
struct rt2800_ops {int /*<<< orphan*/  (* register_multiread ) (struct rt2x00_dev*,unsigned int const,void*,int /*<<< orphan*/  const) ;} ;
struct TYPE_2__ {struct rt2800_ops* drv; } ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct rt2x00_dev*,unsigned int const,void*,int /*<<< orphan*/  const) ; 

__attribute__((used)) static inline void rt2800_register_multiread(struct rt2x00_dev *rt2x00dev,
					     const unsigned int offset,
					     void *value, const u32 length)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	rt2800ops->register_multiread(rt2x00dev, offset, value, length);
}