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
struct dst_state {int type_flags; int /*<<< orphan*/  dst_mutex; } ;

/* Variables and functions */
 int DST_TYPE_HAS_CA ; 
 int DST_TYPE_HAS_FW_BUILD ; 
 int DST_TYPE_HAS_MULTI_FE ; 
 int DST_TYPE_HAS_TS204 ; 
 int /*<<< orphan*/  dprintk (int,char*) ; 
 int dst_addons ; 
 scalar_t__ dst_card_type (struct dst_state*) ; 
 scalar_t__ dst_comm_init (struct dst_state*) ; 
 scalar_t__ dst_fw_ver (struct dst_state*) ; 
 scalar_t__ dst_get_device_id (struct dst_state*) ; 
 scalar_t__ dst_get_mac (struct dst_state*) ; 
 scalar_t__ dst_get_tuner_info (struct dst_state*) ; 
 scalar_t__ dst_get_vendor (struct dst_state*) ; 
 int /*<<< orphan*/  dst_packsize (struct dst_state*,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 scalar_t__ rdc_8820_reset (struct dst_state*) ; 

__attribute__((used)) static int dst_probe(struct dst_state *state)
{
	mutex_init(&state->dst_mutex);
	if (dst_addons & DST_TYPE_HAS_CA) {
		if ((rdc_8820_reset(state)) < 0) {
			pr_err("RDC 8820 RESET Failed.\n");
			return -1;
		}
		msleep(4000);
	} else {
		msleep(100);
	}
	if ((dst_comm_init(state)) < 0) {
		pr_err("DST Initialization Failed.\n");
		return -1;
	}
	msleep(100);
	if (dst_get_device_id(state) < 0) {
		pr_err("unknown device.\n");
		return -1;
	}
	if (dst_get_mac(state) < 0) {
		dprintk(2, "MAC: Unsupported command\n");
	}
	if ((state->type_flags & DST_TYPE_HAS_MULTI_FE) || (state->type_flags & DST_TYPE_HAS_FW_BUILD)) {
		if (dst_get_tuner_info(state) < 0)
			dprintk(2, "Tuner: Unsupported command\n");
	}
	if (state->type_flags & DST_TYPE_HAS_TS204) {
		dst_packsize(state, 204);
	}
	if (state->type_flags & DST_TYPE_HAS_FW_BUILD) {
		if (dst_fw_ver(state) < 0) {
			dprintk(2, "FW: Unsupported command\n");
			return 0;
		}
		if (dst_card_type(state) < 0) {
			dprintk(2, "Card: Unsupported command\n");
			return 0;
		}
		if (dst_get_vendor(state) < 0) {
			dprintk(2, "Vendor: Unsupported command\n");
			return 0;
		}
	}

	return 0;
}