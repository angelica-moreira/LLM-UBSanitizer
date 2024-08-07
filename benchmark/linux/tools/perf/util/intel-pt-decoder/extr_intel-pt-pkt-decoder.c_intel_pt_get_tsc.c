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
struct intel_pt_pkt {int /*<<< orphan*/  payload; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int INTEL_PT_NEED_MORE_BYTES ; 
 int /*<<< orphan*/  INTEL_PT_TSC ; 
 int /*<<< orphan*/  memcpy_le64 (int /*<<< orphan*/ *,unsigned char const*,int) ; 

__attribute__((used)) static int intel_pt_get_tsc(const unsigned char *buf, size_t len,
			    struct intel_pt_pkt *packet)
{
	if (len < 8)
		return INTEL_PT_NEED_MORE_BYTES;
	packet->type = INTEL_PT_TSC;
	memcpy_le64(&packet->payload, buf + 1, 7);
	return 8;
}