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
struct foo_obj {int /*<<< orphan*/  foo; } ;
struct foo_attribute {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int kstrtoint (char const*,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static ssize_t foo_store(struct foo_obj *foo_obj, struct foo_attribute *attr,
			 const char *buf, size_t count)
{
	int ret;

	ret = kstrtoint(buf, 10, &foo_obj->foo);
	if (ret < 0)
		return ret;

	return count;
}