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
typedef  int /*<<< orphan*/  u8 ;
struct list_head {int dummy; } ;
struct bdaddr_list_with_irk {int /*<<< orphan*/  list; int /*<<< orphan*/  local_irk; int /*<<< orphan*/  peer_irk; int /*<<< orphan*/  bdaddr_type; int /*<<< orphan*/  bdaddr; } ;
typedef  int /*<<< orphan*/  bdaddr_t ;

/* Variables and functions */
 int /*<<< orphan*/  BDADDR_ANY ; 
 int EBADF ; 
 int EEXIST ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  bacmp (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bacpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ hci_bdaddr_list_lookup (struct list_head*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct bdaddr_list_with_irk* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,struct list_head*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

int hci_bdaddr_list_add_with_irk(struct list_head *list, bdaddr_t *bdaddr,
					u8 type, u8 *peer_irk, u8 *local_irk)
{
	struct bdaddr_list_with_irk *entry;

	if (!bacmp(bdaddr, BDADDR_ANY))
		return -EBADF;

	if (hci_bdaddr_list_lookup(list, bdaddr, type))
		return -EEXIST;

	entry = kzalloc(sizeof(*entry), GFP_KERNEL);
	if (!entry)
		return -ENOMEM;

	bacpy(&entry->bdaddr, bdaddr);
	entry->bdaddr_type = type;

	if (peer_irk)
		memcpy(entry->peer_irk, peer_irk, 16);

	if (local_irk)
		memcpy(entry->local_irk, local_irk, 16);

	list_add(&entry->list, list);

	return 0;
}