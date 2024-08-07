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
 int adv7511_cec_read (struct v4l2_subdev*,int) ; 
 int adv7511_cec_write (struct v4l2_subdev*,int,int) ; 

__attribute__((used)) static inline int adv7511_cec_write_and_or(struct v4l2_subdev *sd, u8 reg, u8 mask,
				   u8 val)
{
	return adv7511_cec_write(sd, reg, (adv7511_cec_read(sd, reg) & mask) | val);
}