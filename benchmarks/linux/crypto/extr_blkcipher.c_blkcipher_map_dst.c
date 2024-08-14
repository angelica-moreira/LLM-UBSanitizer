#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  addr; } ;
struct TYPE_4__ {TYPE_1__ virt; } ;
struct blkcipher_walk {int /*<<< orphan*/  out; TYPE_2__ dst; } ;

/* Variables and functions */
 int /*<<< orphan*/  scatterwalk_map (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void blkcipher_map_dst(struct blkcipher_walk *walk)
{
	walk->dst.virt.addr = scatterwalk_map(&walk->out);
}