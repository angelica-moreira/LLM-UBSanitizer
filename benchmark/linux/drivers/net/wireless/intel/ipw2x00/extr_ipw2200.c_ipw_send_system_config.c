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
struct ipw_priv {int /*<<< orphan*/  sys_config; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPW_CMD_SYSTEM_CONFIG ; 
 int ipw_send_cmd_pdu (struct ipw_priv*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int ipw_send_system_config(struct ipw_priv *priv)
{
	return ipw_send_cmd_pdu(priv, IPW_CMD_SYSTEM_CONFIG,
				sizeof(priv->sys_config),
				&priv->sys_config);
}