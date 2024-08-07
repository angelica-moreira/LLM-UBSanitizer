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
struct device {int /*<<< orphan*/  parent; } ;
struct ab3100 {scalar_t__ chip_id; } ;

/* Variables and functions */
 struct ab3100* dev_get_drvdata (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ab3100_get_chip_id(struct device *dev)
{
	struct ab3100 *ab3100 = dev_get_drvdata(dev->parent);

	return (int)ab3100->chip_id;
}