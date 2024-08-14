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
struct sk_buff {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  common; } ;
struct ncsi_cmd_ebf_pkt {TYPE_1__ cmd; int /*<<< orphan*/  mode; } ;
struct ncsi_cmd_arg {int /*<<< orphan*/ * dwords; } ;

/* Variables and functions */
 int /*<<< orphan*/  htonl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ncsi_cmd_build_header (int /*<<< orphan*/ *,struct ncsi_cmd_arg*) ; 
 struct ncsi_cmd_ebf_pkt* skb_put_zero (struct sk_buff*,int) ; 

__attribute__((used)) static int ncsi_cmd_handler_ebf(struct sk_buff *skb,
				struct ncsi_cmd_arg *nca)
{
	struct ncsi_cmd_ebf_pkt *cmd;

	cmd = skb_put_zero(skb, sizeof(*cmd));
	cmd->mode = htonl(nca->dwords[0]);
	ncsi_cmd_build_header(&cmd->cmd.common, nca);

	return 0;
}