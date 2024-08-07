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
struct sti_tvout {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 struct sti_tvout* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  sti_tvout_destroy_encoders (struct sti_tvout*) ; 

__attribute__((used)) static void sti_tvout_unbind(struct device *dev, struct device *master,
	void *data)
{
	struct sti_tvout *tvout = dev_get_drvdata(dev);

	sti_tvout_destroy_encoders(tvout);
}