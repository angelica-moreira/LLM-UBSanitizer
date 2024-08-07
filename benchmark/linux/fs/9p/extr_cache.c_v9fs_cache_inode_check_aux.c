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
typedef  int uint16_t ;
struct TYPE_2__ {int /*<<< orphan*/  version; } ;
struct v9fs_inode {TYPE_1__ qid; } ;
typedef  int /*<<< orphan*/  loff_t ;
typedef  enum fscache_checkaux { ____Placeholder_fscache_checkaux } fscache_checkaux ;

/* Variables and functions */
 int FSCACHE_CHECKAUX_OBSOLETE ; 
 int FSCACHE_CHECKAUX_OKAY ; 
 scalar_t__ memcmp (void const*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static enum
fscache_checkaux v9fs_cache_inode_check_aux(void *cookie_netfs_data,
					    const void *buffer,
					    uint16_t buflen,
					    loff_t object_size)
{
	const struct v9fs_inode *v9inode = cookie_netfs_data;

	if (buflen != sizeof(v9inode->qid.version))
		return FSCACHE_CHECKAUX_OBSOLETE;

	if (memcmp(buffer, &v9inode->qid.version,
		   sizeof(v9inode->qid.version)))
		return FSCACHE_CHECKAUX_OBSOLETE;

	return FSCACHE_CHECKAUX_OKAY;
}