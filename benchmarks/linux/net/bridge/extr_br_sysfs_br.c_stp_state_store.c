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
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  set_stp_state ; 
 int /*<<< orphan*/  store_bridge_parm (struct device*,char const*,size_t,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t stp_state_store(struct device *d,
			       struct device_attribute *attr, const char *buf,
			       size_t len)
{
	return store_bridge_parm(d, buf, len, set_stp_state);
}