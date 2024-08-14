#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct sk_buff {int dummy; } ;
struct nlattr {int dummy; } ;
struct genl_info {struct nlattr** attrs; } ;
struct fd {TYPE_2__* file; } ;
struct cgroupstats {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  dentry; } ;
struct TYPE_4__ {TYPE_1__ f_path; } ;

/* Variables and functions */
 size_t CGROUPSTATS_CMD_ATTR_FD ; 
 int /*<<< orphan*/  CGROUPSTATS_CMD_NEW ; 
 int /*<<< orphan*/  CGROUPSTATS_TYPE_CGROUP_STATS ; 
 int EINVAL ; 
 int EMSGSIZE ; 
 int cgroupstats_build (struct cgroupstats*,int /*<<< orphan*/ ) ; 
 struct fd fdget (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fdput (struct fd) ; 
 int /*<<< orphan*/  memset (struct cgroupstats*,int /*<<< orphan*/ ,int) ; 
 struct cgroupstats* nla_data (struct nlattr*) ; 
 int /*<<< orphan*/  nla_get_u32 (struct nlattr*) ; 
 struct nlattr* nla_reserve (struct sk_buff*,int /*<<< orphan*/ ,int) ; 
 size_t nla_total_size (int) ; 
 int /*<<< orphan*/  nlmsg_free (struct sk_buff*) ; 
 int prepare_reply (struct genl_info*,int /*<<< orphan*/ ,struct sk_buff**,size_t) ; 
 int send_reply (struct sk_buff*,struct genl_info*) ; 

__attribute__((used)) static int cgroupstats_user_cmd(struct sk_buff *skb, struct genl_info *info)
{
	int rc = 0;
	struct sk_buff *rep_skb;
	struct cgroupstats *stats;
	struct nlattr *na;
	size_t size;
	u32 fd;
	struct fd f;

	na = info->attrs[CGROUPSTATS_CMD_ATTR_FD];
	if (!na)
		return -EINVAL;

	fd = nla_get_u32(info->attrs[CGROUPSTATS_CMD_ATTR_FD]);
	f = fdget(fd);
	if (!f.file)
		return 0;

	size = nla_total_size(sizeof(struct cgroupstats));

	rc = prepare_reply(info, CGROUPSTATS_CMD_NEW, &rep_skb,
				size);
	if (rc < 0)
		goto err;

	na = nla_reserve(rep_skb, CGROUPSTATS_TYPE_CGROUP_STATS,
				sizeof(struct cgroupstats));
	if (na == NULL) {
		nlmsg_free(rep_skb);
		rc = -EMSGSIZE;
		goto err;
	}

	stats = nla_data(na);
	memset(stats, 0, sizeof(*stats));

	rc = cgroupstats_build(stats, f.file->f_path.dentry);
	if (rc < 0) {
		nlmsg_free(rep_skb);
		goto err;
	}

	rc = send_reply(rep_skb, info);

err:
	fdput(f);
	return rc;
}