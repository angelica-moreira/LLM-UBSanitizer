#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct cifsInodeInfo {int dummy; } ;
struct TCP_Server_Info {TYPE_1__* ops; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* set_oplock_level ) (struct cifsInodeInfo*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  SMB2_LEASE_READ_CACHING_HE ; 
 int /*<<< orphan*/  stub1 (struct cifsInodeInfo*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
smb21_downgrade_oplock(struct TCP_Server_Info *server,
		       struct cifsInodeInfo *cinode, bool set_level2)
{
	server->ops->set_oplock_level(cinode,
				      set_level2 ? SMB2_LEASE_READ_CACHING_HE :
				      0, 0, NULL);
}