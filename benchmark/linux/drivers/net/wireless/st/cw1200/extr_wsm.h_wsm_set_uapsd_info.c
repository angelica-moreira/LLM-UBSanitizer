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
struct wsm_uapsd_info {int dummy; } ;
struct cw1200_common {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WSM_MIB_ID_SET_UAPSD_INFORMATION ; 
 int wsm_write_mib (struct cw1200_common*,int /*<<< orphan*/ ,struct wsm_uapsd_info*,int) ; 

__attribute__((used)) static inline int wsm_set_uapsd_info(struct cw1200_common *priv,
				     struct wsm_uapsd_info *arg)
{
	return wsm_write_mib(priv, WSM_MIB_ID_SET_UAPSD_INFORMATION,
				arg, sizeof(*arg));
}