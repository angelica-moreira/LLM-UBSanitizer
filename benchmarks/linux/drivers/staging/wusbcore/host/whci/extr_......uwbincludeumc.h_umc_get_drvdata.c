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
struct umc_dev {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 void* dev_get_drvdata (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void *umc_get_drvdata(struct umc_dev *umc_dev)
{
	return dev_get_drvdata(&umc_dev->dev);
}