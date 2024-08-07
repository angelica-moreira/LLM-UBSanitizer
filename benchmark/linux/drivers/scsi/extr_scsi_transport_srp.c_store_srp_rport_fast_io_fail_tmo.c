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
struct srp_rport {int fast_io_fail_tmo; int /*<<< orphan*/  dev_loss_tmo; int /*<<< orphan*/  reconnect_delay; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int srp_parse_tmo (int*,char const*) ; 
 int srp_tmo_valid (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 struct srp_rport* transport_class_to_srp_rport (struct device*) ; 

__attribute__((used)) static ssize_t store_srp_rport_fast_io_fail_tmo(struct device *dev,
						struct device_attribute *attr,
						const char *buf, size_t count)
{
	struct srp_rport *rport = transport_class_to_srp_rport(dev);
	int res;
	int fast_io_fail_tmo;

	res = srp_parse_tmo(&fast_io_fail_tmo, buf);
	if (res)
		goto out;
	res = srp_tmo_valid(rport->reconnect_delay, fast_io_fail_tmo,
			    rport->dev_loss_tmo);
	if (res)
		goto out;
	rport->fast_io_fail_tmo = fast_io_fail_tmo;
	res = count;

out:
	return res;
}