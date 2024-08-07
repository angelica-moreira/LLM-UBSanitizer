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
struct wireless_dev {int dummy; } ;
struct cfg80211_registered_device {int /*<<< orphan*/  wiphy; TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* stop_nan ) (int /*<<< orphan*/ *,struct wireless_dev*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *,struct wireless_dev*) ; 
 int /*<<< orphan*/  trace_rdev_return_void (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace_rdev_stop_nan (int /*<<< orphan*/ *,struct wireless_dev*) ; 

__attribute__((used)) static inline void rdev_stop_nan(struct cfg80211_registered_device *rdev,
				 struct wireless_dev *wdev)
{
	trace_rdev_stop_nan(&rdev->wiphy, wdev);
	rdev->ops->stop_nan(&rdev->wiphy, wdev);
	trace_rdev_return_void(&rdev->wiphy);
}