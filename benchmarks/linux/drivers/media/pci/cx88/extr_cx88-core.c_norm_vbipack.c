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
typedef  int v4l2_std_id ;

/* Variables and functions */
 int V4L2_STD_625_50 ; 

__attribute__((used)) static inline unsigned int norm_vbipack(v4l2_std_id norm)
{
	return (norm & V4L2_STD_625_50) ? 511 : 400;
}