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
typedef  int /*<<< orphan*/  u8 ;
struct dsaf_device {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void *hns_dsaf_dev_priv(const struct dsaf_device *dsaf_dev)
{
	return (void *)((u8 *)dsaf_dev + sizeof(*dsaf_dev));
}