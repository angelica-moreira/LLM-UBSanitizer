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
struct TYPE_3__ {int /*<<< orphan*/  state; } ;
struct rcar_du_plane {TYPE_1__ plane; } ;
struct rcar_du_format_info {int dummy; } ;
struct TYPE_4__ {struct rcar_du_format_info const* format; } ;

/* Variables and functions */
 TYPE_2__* to_rcar_plane_state (int /*<<< orphan*/ ) ; 

__attribute__((used)) static const struct rcar_du_format_info *
plane_format(struct rcar_du_plane *plane)
{
	return to_rcar_plane_state(plane->plane.state)->format;
}