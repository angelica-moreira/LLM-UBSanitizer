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
typedef  int /*<<< orphan*/  verifier_state_t ;
typedef  int uint32_t ;
typedef  int /*<<< orphan*/  drm_via_private_t ;

/* Variables and functions */
 int /*<<< orphan*/  state_command ; 
 int /*<<< orphan*/  via_write (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static __inline__ verifier_state_t
via_parse_vheader6(drm_via_private_t *dev_priv, uint32_t const **buffer,
		   const uint32_t *buf_end)
{

	uint32_t addr, count, i;
	const uint32_t *buf = *buffer;

	i = count = *++buf;
	buf += 3;
	while (i--) {
		addr = *buf++;
		via_write(dev_priv, addr, *buf++);
	}
	count <<= 1;
	if (count & 3)
		buf += 4 - (count & 3);
	*buffer = buf;
	return state_command;
}