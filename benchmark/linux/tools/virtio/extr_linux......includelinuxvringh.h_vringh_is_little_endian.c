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
struct vringh {scalar_t__ little_endian; } ;

/* Variables and functions */
 scalar_t__ virtio_legacy_is_little_endian () ; 

__attribute__((used)) static inline bool vringh_is_little_endian(const struct vringh *vrh)
{
	return vrh->little_endian ||
		virtio_legacy_is_little_endian();
}