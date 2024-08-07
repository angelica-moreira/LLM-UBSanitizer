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
struct wsm_p2p_ps_modeinfo {int dummy; } ;
struct cw1200_common {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WSM_MIB_ID_P2P_PS_MODE_INFO ; 
 int wsm_read_mib (struct cw1200_common*,int /*<<< orphan*/ ,struct wsm_p2p_ps_modeinfo*,int) ; 

__attribute__((used)) static inline int wsm_get_p2p_ps_modeinfo(struct cw1200_common *priv,
					  struct wsm_p2p_ps_modeinfo *mi)
{
	return wsm_read_mib(priv, WSM_MIB_ID_P2P_PS_MODE_INFO,
			    mi, sizeof(*mi));
}