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
struct fp_ext {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  uprint (char*) ; 

struct fp_ext *
fp_fsincos0(struct fp_ext *dest, struct fp_ext *src)
{
	uprint("fsincos0\n");

	return dest;
}