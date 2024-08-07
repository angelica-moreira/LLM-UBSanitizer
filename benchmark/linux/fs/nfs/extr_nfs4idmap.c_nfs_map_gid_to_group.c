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
struct nfs_server {int caps; TYPE_1__* nfs_client; } ;
struct idmap {int dummy; } ;
typedef  int /*<<< orphan*/  kgid_t ;
typedef  int /*<<< orphan*/  __u32 ;
struct TYPE_2__ {struct idmap* cl_idmap; } ;

/* Variables and functions */
 int EINVAL ; 
 int NFS_CAP_UIDGID_NOMAP ; 
 int /*<<< orphan*/  from_kgid_munged (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idmap_userns (struct idmap*) ; 
 int nfs_idmap_lookup_name (int /*<<< orphan*/ ,char*,char*,size_t,struct idmap*) ; 
 int nfs_map_numeric_to_string (int /*<<< orphan*/ ,char*,size_t) ; 
 int /*<<< orphan*/  trace_nfs4_map_gid_to_group (char*,int,int /*<<< orphan*/ ,int) ; 

int nfs_map_gid_to_group(const struct nfs_server *server, kgid_t gid, char *buf, size_t buflen)
{
	struct idmap *idmap = server->nfs_client->cl_idmap;
	int ret = -EINVAL;
	__u32 id;

	id = from_kgid_munged(idmap_userns(idmap), gid);
	if (!(server->caps & NFS_CAP_UIDGID_NOMAP))
		ret = nfs_idmap_lookup_name(id, "group", buf, buflen, idmap);
	if (ret < 0)
		ret = nfs_map_numeric_to_string(id, buf, buflen);
	trace_nfs4_map_gid_to_group(buf, ret, id, ret);
	return ret;
}