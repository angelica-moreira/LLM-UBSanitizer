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
struct dsaf_device {int /*<<< orphan*/  ae_dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  hnae_ae_unregister (int /*<<< orphan*/ *) ; 

void hns_dsaf_ae_uninit(struct dsaf_device *dsaf_dev)
{
	hnae_ae_unregister(&dsaf_dev->ae_dev);
}