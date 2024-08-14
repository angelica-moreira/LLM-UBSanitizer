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
struct arm_spe_pkt {unsigned char index; int /*<<< orphan*/  type; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARM_SPE_CONTEXT ; 
 int arm_spe_get_payload (unsigned char const*,size_t,struct arm_spe_pkt*) ; 

__attribute__((used)) static int arm_spe_get_context(const unsigned char *buf, size_t len,
			       struct arm_spe_pkt *packet)
{
	packet->type = ARM_SPE_CONTEXT;
	packet->index = buf[0] & 0x3;

	return arm_spe_get_payload(buf, len, packet);
}