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
 int /*<<< orphan*/  SETUP_FB (struct stifb_info*) ; 
 int /*<<< orphan*/  SETUP_RAMDAC (struct stifb_info*) ; 

__attribute__((used)) static void
elkSetupPlanes(struct stifb_info *fb)
{
	SETUP_RAMDAC(fb);
	SETUP_FB(fb);
}