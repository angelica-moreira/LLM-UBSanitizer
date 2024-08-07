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
 int /*<<< orphan*/  ad9389b_wr_and_or (struct v4l2_subdev*,int,int,int) ; 

__attribute__((used)) static void ad9389b_csc_conversion_mode(struct v4l2_subdev *sd, u8 mode)
{
	ad9389b_wr_and_or(sd, 0x17, 0xe7, (mode & 0x3)<<3);
	ad9389b_wr_and_or(sd, 0x18, 0x9f, (mode & 0x3)<<5);
}