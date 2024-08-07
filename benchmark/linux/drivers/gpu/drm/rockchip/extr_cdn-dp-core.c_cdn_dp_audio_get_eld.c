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
typedef  int /*<<< orphan*/  u8 ;
struct device {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  eld; } ;
struct cdn_dp_device {TYPE_1__ connector; } ;

/* Variables and functions */
 struct cdn_dp_device* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  min (int,size_t) ; 

__attribute__((used)) static int cdn_dp_audio_get_eld(struct device *dev, void *data,
				u8 *buf, size_t len)
{
	struct cdn_dp_device *dp = dev_get_drvdata(dev);

	memcpy(buf, dp->connector.eld, min(sizeof(dp->connector.eld), len));

	return 0;
}