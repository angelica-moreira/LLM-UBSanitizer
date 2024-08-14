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
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_3__ {int /*<<< orphan*/  vsp1; } ;
struct TYPE_4__ {TYPE_1__ entity; } ;
struct vsp1_hgo {TYPE_2__ histo; } ;

/* Variables and functions */
 int /*<<< orphan*/  vsp1_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u32 vsp1_hgo_read(struct vsp1_hgo *hgo, u32 reg)
{
	return vsp1_read(hgo->histo.entity.vsp1, reg);
}