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
struct wsm_mib_counters_table {int dummy; } ;
struct cw1200_common {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  WSM_MIB_ID_COUNTERS_TABLE ; 
 int wsm_read_mib (struct cw1200_common*,int /*<<< orphan*/ ,struct wsm_mib_counters_table*,int) ; 

__attribute__((used)) static inline int wsm_get_counters_table(struct cw1200_common *priv,
					 struct wsm_mib_counters_table *arg)
{
	return wsm_read_mib(priv, WSM_MIB_ID_COUNTERS_TABLE,
			    arg, sizeof(*arg));
}