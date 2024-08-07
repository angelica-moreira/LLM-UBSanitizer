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
struct r8152 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  r8152_aldps_en (struct r8152*,int) ; 
 int /*<<< orphan*/  rtl_disable (struct r8152*) ; 

__attribute__((used)) static void rtl8152_disable(struct r8152 *tp)
{
	r8152_aldps_en(tp, false);
	rtl_disable(tp);
	r8152_aldps_en(tp, true);
}