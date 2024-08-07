#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {int ref_freq; } ;
struct TYPE_16__ {TYPE_7__ pll; } ;
struct TYPE_13__ {int system; } ;
struct TYPE_12__ {int mctlwtst; } ;
struct TYPE_14__ {TYPE_5__ pll; TYPE_4__ reg; } ;
struct TYPE_10__ {int vcomax; } ;
struct TYPE_9__ {int vcomax; } ;
struct TYPE_11__ {TYPE_2__ system; TYPE_1__ pixel; } ;
struct matrox_fb_info {TYPE_8__ features; TYPE_6__ values; TYPE_3__ limits; } ;

/* Variables and functions */

__attribute__((used)) static void default_pins2(struct matrox_fb_info *minfo)
{
	/* Millennium II, Mystique */
	minfo->limits.pixel.vcomax	=
	minfo->limits.system.vcomax	= 230000;
	minfo->values.reg.mctlwtst	= 0x00030101;
	minfo->values.pll.system	=  50000;
	minfo->features.pll.ref_freq	=  14318;
}