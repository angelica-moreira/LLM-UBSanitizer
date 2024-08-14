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
typedef  int u32 ;
struct v4l2_subdev {int dummy; } ;

/* Variables and functions */
 int venc_read (struct v4l2_subdev*,int) ; 
 int /*<<< orphan*/  venc_write (struct v4l2_subdev*,int,int) ; 

__attribute__((used)) static inline u32 venc_modify(struct v4l2_subdev *sd, u32 offset,
				 u32 val, u32 mask)
{
	u32 new_val = (venc_read(sd, offset) & ~mask) | (val & mask);

	venc_write(sd, offset, new_val);

	return new_val;
}