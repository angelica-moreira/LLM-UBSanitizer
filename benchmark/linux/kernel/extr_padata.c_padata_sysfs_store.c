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
struct padata_sysfs_entry {int /*<<< orphan*/  (* store ) (struct padata_instance*,struct attribute*,char const*,size_t) ;scalar_t__ show; } ;
struct padata_instance {int dummy; } ;
struct kobject {int dummy; } ;
struct attribute {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  EIO ; 
 struct padata_sysfs_entry* attr2pentry (struct attribute*) ; 
 struct padata_instance* kobj2pinst (struct kobject*) ; 
 int /*<<< orphan*/  stub1 (struct padata_instance*,struct attribute*,char const*,size_t) ; 

__attribute__((used)) static ssize_t padata_sysfs_store(struct kobject *kobj, struct attribute *attr,
				  const char *buf, size_t count)
{
	struct padata_instance *pinst;
	struct padata_sysfs_entry *pentry;
	ssize_t ret = -EIO;

	pinst = kobj2pinst(kobj);
	pentry = attr2pentry(attr);
	if (pentry->show)
		ret = pentry->store(pinst, attr, buf, count);

	return ret;
}