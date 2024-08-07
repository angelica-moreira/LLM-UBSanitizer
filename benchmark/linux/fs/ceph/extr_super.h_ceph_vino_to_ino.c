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
struct ceph_vino {int /*<<< orphan*/  ino; } ;
typedef  int /*<<< orphan*/  ino_t ;

/* Variables and functions */
 int /*<<< orphan*/  ceph_ino_to_ino32 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline ino_t ceph_vino_to_ino(struct ceph_vino vino)
{
#if BITS_PER_LONG == 32
	return ceph_ino_to_ino32(vino.ino);
#else
	return (ino_t)vino.ino;
#endif
}