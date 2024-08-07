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
struct pvr2_hdw {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 scalar_t__ do_i2c_probe (struct pvr2_hdw*,int) ; 
 int /*<<< orphan*/  pr_info (char*,int /*<<< orphan*/ ,...) ; 

__attribute__((used)) static void do_i2c_scan(struct pvr2_hdw *hdw)
{
	int i;
	pr_info("%s: i2c scan beginning\n", hdw->name);
	for (i = 0; i < 128; i++) {
		if (do_i2c_probe(hdw, i)) {
			pr_info("%s: i2c scan: found device @ 0x%x\n",
			       hdw->name, i);
		}
	}
	pr_info("%s: i2c scan done.\n", hdw->name);
}