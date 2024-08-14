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
struct smscore_registry_entry_t {int /*<<< orphan*/  entry; int /*<<< orphan*/  devpath; int /*<<< orphan*/  mode; } ;
struct list_head {struct list_head* next; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  default_mode ; 
 struct list_head g_smscore_registry ; 
 int /*<<< orphan*/  g_smscore_registrylock ; 
 struct smscore_registry_entry_t* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kmutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kmutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,struct list_head*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  strncmp (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  strscpy (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static struct smscore_registry_entry_t *smscore_find_registry(char *devpath)
{
	struct smscore_registry_entry_t *entry;
	struct list_head *next;

	kmutex_lock(&g_smscore_registrylock);
	for (next = g_smscore_registry.next;
	     next != &g_smscore_registry;
	     next = next->next) {
		entry = (struct smscore_registry_entry_t *) next;
		if (!strncmp(entry->devpath, devpath, sizeof(entry->devpath))) {
			kmutex_unlock(&g_smscore_registrylock);
			return entry;
		}
	}
	entry = kmalloc(sizeof(*entry), GFP_KERNEL);
	if (entry) {
		entry->mode = default_mode;
		strscpy(entry->devpath, devpath, sizeof(entry->devpath));
		list_add(&entry->entry, &g_smscore_registry);
	} else
		pr_err("failed to create smscore_registry.\n");
	kmutex_unlock(&g_smscore_registrylock);
	return entry;
}