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
struct mip4_ts {int dummy; } ;
struct input_dev {int dummy; } ;

/* Variables and functions */
 struct mip4_ts* input_get_drvdata (struct input_dev*) ; 
 int /*<<< orphan*/  mip4_disable (struct mip4_ts*) ; 

__attribute__((used)) static void mip4_input_close(struct input_dev *dev)
{
	struct mip4_ts *ts = input_get_drvdata(dev);

	mip4_disable(ts);
}