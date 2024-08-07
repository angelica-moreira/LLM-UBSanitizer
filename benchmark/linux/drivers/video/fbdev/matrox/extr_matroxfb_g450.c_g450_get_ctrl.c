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
struct v4l2_control {int /*<<< orphan*/  value; int /*<<< orphan*/  id; } ;
struct matrox_fb_info {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int get_ctrl_id (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * get_ctrl_ptr (struct matrox_fb_info*,int) ; 

__attribute__((used)) static int g450_get_ctrl(void* md, struct v4l2_control *p) {
	int i;
	struct matrox_fb_info *minfo = md;
	
	i = get_ctrl_id(p->id);
	if (i < 0) return -EINVAL;
	p->value = *get_ctrl_ptr(minfo, i);
	return 0;
}