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
typedef  int /*<<< orphan*/  u32 ;
struct g2d_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  BITBLT_COMMAND_REG ; 
 int /*<<< orphan*/  w (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void g2d_set_cmd(struct g2d_dev *d, u32 c)
{
	w(c, BITBLT_COMMAND_REG);
}