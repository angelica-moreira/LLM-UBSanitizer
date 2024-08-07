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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {struct scmi_perf_set_limits* buf; } ;
struct scmi_xfer {TYPE_1__ tx; } ;
struct scmi_perf_set_limits {void* min_level; void* max_level; void* domain; } ;
struct scmi_handle {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PERF_LIMITS_SET ; 
 int /*<<< orphan*/  SCMI_PROTOCOL_PERF ; 
 void* cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int scmi_do_xfer (struct scmi_handle const*,struct scmi_xfer*) ; 
 int scmi_xfer_get_init (struct scmi_handle const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,struct scmi_xfer**) ; 
 int /*<<< orphan*/  scmi_xfer_put (struct scmi_handle const*,struct scmi_xfer*) ; 

__attribute__((used)) static int scmi_perf_mb_limits_set(const struct scmi_handle *handle, u32 domain,
				   u32 max_perf, u32 min_perf)
{
	int ret;
	struct scmi_xfer *t;
	struct scmi_perf_set_limits *limits;

	ret = scmi_xfer_get_init(handle, PERF_LIMITS_SET, SCMI_PROTOCOL_PERF,
				 sizeof(*limits), 0, &t);
	if (ret)
		return ret;

	limits = t->tx.buf;
	limits->domain = cpu_to_le32(domain);
	limits->max_level = cpu_to_le32(max_perf);
	limits->min_level = cpu_to_le32(min_perf);

	ret = scmi_do_xfer(handle, t);

	scmi_xfer_put(handle, t);
	return ret;
}