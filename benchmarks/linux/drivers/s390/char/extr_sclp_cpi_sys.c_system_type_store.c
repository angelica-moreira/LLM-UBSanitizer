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
struct kobject {int dummy; } ;
struct kobj_attribute {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int check_string (char*,char const*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sclp_cpi_mutex ; 
 int /*<<< orphan*/  set_string (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  system_type ; 

__attribute__((used)) static ssize_t system_type_store(struct kobject *kobj,
				 struct kobj_attribute *attr,
				 const char *buf,
	size_t len)
{
	int rc;

	rc = check_string("system_type", buf);
	if (rc)
		return rc;

	mutex_lock(&sclp_cpi_mutex);
	set_string(system_type, buf);
	mutex_unlock(&sclp_cpi_mutex);

	return len;
}