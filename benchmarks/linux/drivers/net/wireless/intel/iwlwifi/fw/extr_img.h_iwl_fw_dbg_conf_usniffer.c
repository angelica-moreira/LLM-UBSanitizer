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
typedef  size_t u8 ;
struct iwl_fw_dbg_conf_tlv {int usniffer; } ;
struct TYPE_2__ {struct iwl_fw_dbg_conf_tlv** conf_tlv; } ;
struct iwl_fw {TYPE_1__ dbg; } ;

/* Variables and functions */

__attribute__((used)) static inline bool
iwl_fw_dbg_conf_usniffer(const struct iwl_fw *fw, u8 id)
{
	const struct iwl_fw_dbg_conf_tlv *conf_tlv = fw->dbg.conf_tlv[id];

	if (!conf_tlv)
		return false;

	return conf_tlv->usniffer;
}