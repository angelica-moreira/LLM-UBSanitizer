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
struct hideep_ts {TYPE_1__* client; } ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_be32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int hideep_pgm_w_mem (struct hideep_ts*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int hideep_pgm_w_reg(struct hideep_ts *ts, u32 addr, u32 val)
{
	__be32 data = cpu_to_be32(val);
	int error;

	error = hideep_pgm_w_mem(ts, addr, &data, 1);
	if (error) {
		dev_err(&ts->client->dev,
			"write to register %#08x (%#08x) failed: %d\n",
			addr, val, error);
		return error;
	}

	return 0;
}