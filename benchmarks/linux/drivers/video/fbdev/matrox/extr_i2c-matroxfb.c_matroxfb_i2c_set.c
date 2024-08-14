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
struct matrox_fb_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  matroxfb_set_gpio (struct matrox_fb_info*,int,int) ; 

__attribute__((used)) static inline void matroxfb_i2c_set(struct matrox_fb_info* minfo, int mask, int state) {
	if (state)
		state = 0;
	else
		state = mask;
	matroxfb_set_gpio(minfo, ~mask, state);
}