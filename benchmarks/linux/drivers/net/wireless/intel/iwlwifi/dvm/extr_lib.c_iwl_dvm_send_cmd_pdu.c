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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct iwl_priv {int dummy; } ;
struct iwl_host_cmd {int /*<<< orphan*/  flags; int /*<<< orphan*/  data; int /*<<< orphan*/  len; int /*<<< orphan*/  id; } ;

/* Variables and functions */
 int iwl_dvm_send_cmd (struct iwl_priv*,struct iwl_host_cmd*) ; 

int iwl_dvm_send_cmd_pdu(struct iwl_priv *priv, u8 id,
			 u32 flags, u16 len, const void *data)
{
	struct iwl_host_cmd cmd = {
		.id = id,
		.len = { len, },
		.data = { data, },
		.flags = flags,
	};

	return iwl_dvm_send_cmd(priv, &cmd);
}