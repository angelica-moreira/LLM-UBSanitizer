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
struct srp_rport {int /*<<< orphan*/  fast_io_fail_tmo; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  srp_show_tmo (char*,int /*<<< orphan*/ ) ; 
 struct srp_rport* transport_class_to_srp_rport (struct device*) ; 

__attribute__((used)) static ssize_t show_srp_rport_fast_io_fail_tmo(struct device *dev,
					       struct device_attribute *attr,
					       char *buf)
{
	struct srp_rport *rport = transport_class_to_srp_rport(dev);

	return srp_show_tmo(buf, rport->fast_io_fail_tmo);
}