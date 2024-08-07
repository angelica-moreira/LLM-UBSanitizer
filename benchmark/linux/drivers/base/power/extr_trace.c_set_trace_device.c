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
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEVHASH ; 
 int /*<<< orphan*/  DEVSEED ; 
 int /*<<< orphan*/  dev_hash_value ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  hash_string (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void set_trace_device(struct device *dev)
{
	dev_hash_value = hash_string(DEVSEED, dev_name(dev), DEVHASH);
}