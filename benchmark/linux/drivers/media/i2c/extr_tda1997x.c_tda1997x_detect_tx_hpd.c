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
typedef  int u8 ;
struct v4l2_subdev {int dummy; } ;

/* Variables and functions */
 int DETECT_HPD ; 
 int /*<<< orphan*/  REG_DETECT_5V ; 
 int io_read (struct v4l2_subdev*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool
tda1997x_detect_tx_hpd(struct v4l2_subdev *sd)
{
	u8 reg = io_read(sd, REG_DETECT_5V);

	return ((reg & DETECT_HPD) ? 1 : 0);
}