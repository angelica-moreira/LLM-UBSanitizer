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
struct v4l2_subdev {int dummy; } ;
struct v4l2_async_subdev {int dummy; } ;
struct v4l2_async_notifier {TYPE_1__* ops; } ;
struct TYPE_2__ {int (* bound ) (struct v4l2_async_notifier*,struct v4l2_subdev*,struct v4l2_async_subdev*) ;} ;

/* Variables and functions */
 int stub1 (struct v4l2_async_notifier*,struct v4l2_subdev*,struct v4l2_async_subdev*) ; 

__attribute__((used)) static int v4l2_async_notifier_call_bound(struct v4l2_async_notifier *n,
					  struct v4l2_subdev *subdev,
					  struct v4l2_async_subdev *asd)
{
	if (!n->ops || !n->ops->bound)
		return 0;

	return n->ops->bound(n, subdev, asd);
}