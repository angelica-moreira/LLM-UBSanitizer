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
struct storvsc_device {scalar_t__ destroy; } ;
struct hv_device {int dummy; } ;

/* Variables and functions */
 struct storvsc_device* hv_get_drvdata (struct hv_device*) ; 

__attribute__((used)) static inline struct storvsc_device *get_out_stor_device(
					struct hv_device *device)
{
	struct storvsc_device *stor_device;

	stor_device = hv_get_drvdata(device);

	if (stor_device && stor_device->destroy)
		stor_device = NULL;

	return stor_device;
}