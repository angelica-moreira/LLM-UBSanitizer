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
typedef  int /*<<< orphan*/  u64 ;
struct wireless_dev {int dummy; } ;
struct cfg80211_registered_device {int /*<<< orphan*/  wiphy; TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* del_nan_func ) (int /*<<< orphan*/ *,struct wireless_dev*,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *,struct wireless_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_rdev_del_nan_func (int /*<<< orphan*/ *,struct wireless_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_rdev_return_void (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void rdev_del_nan_func(struct cfg80211_registered_device *rdev,
				    struct wireless_dev *wdev, u64 cookie)
{
	trace_rdev_del_nan_func(&rdev->wiphy, wdev, cookie);
	rdev->ops->del_nan_func(&rdev->wiphy, wdev, cookie);
	trace_rdev_return_void(&rdev->wiphy);
}