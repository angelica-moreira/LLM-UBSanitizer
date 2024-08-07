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
struct adapter {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ cxgb4_mps_ref_inc (struct adapter*,int /*<<< orphan*/  const*,int,int /*<<< orphan*/  const*) ; 
 int t4_alloc_raw_mac_filt (struct adapter*,unsigned int,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  t4_free_raw_mac_filt (struct adapter*,unsigned int,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

int cxgb4_alloc_raw_mac_filt(struct adapter *adap,
			     unsigned int viid,
			     const u8 *addr,
			     const u8 *mask,
			     unsigned int idx,
			     u8 lookup_type,
			     u8 port_id,
			     bool sleep_ok)
{
	int ret;

	ret = t4_alloc_raw_mac_filt(adap, viid, addr,
				    mask, idx, lookup_type,
				    port_id, sleep_ok);
	if (ret < 0)
		return ret;

	if (cxgb4_mps_ref_inc(adap, addr, ret, mask)) {
		ret = -ENOMEM;
		t4_free_raw_mac_filt(adap, viid, addr,
				     mask, idx, lookup_type,
				     port_id, sleep_ok);
	}

	return ret;
}