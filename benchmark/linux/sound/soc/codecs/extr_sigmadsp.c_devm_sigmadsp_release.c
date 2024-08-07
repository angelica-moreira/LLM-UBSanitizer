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
struct sigmadsp {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sigmadsp_firmware_release (struct sigmadsp*) ; 

__attribute__((used)) static void devm_sigmadsp_release(struct device *dev, void *res)
{
	sigmadsp_firmware_release((struct sigmadsp *)res);
}