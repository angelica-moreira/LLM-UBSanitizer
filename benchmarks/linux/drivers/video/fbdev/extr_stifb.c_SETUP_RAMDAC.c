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
struct stifb_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  SETUP_HW (struct stifb_info*) ; 
 int /*<<< orphan*/  WRITE_WORD (int,struct stifb_info*,int) ; 

__attribute__((used)) static void
SETUP_RAMDAC(struct stifb_info *fb) 
{
	SETUP_HW(fb);
	WRITE_WORD(0x04000000, fb, 0x1020);
	WRITE_WORD(0xff000000, fb, 0x1028);
}