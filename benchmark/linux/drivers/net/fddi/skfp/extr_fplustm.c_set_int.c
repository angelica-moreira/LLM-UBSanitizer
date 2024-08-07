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

/* Variables and functions */

__attribute__((used)) static void set_int(char *p, int l)
{
	p[0] = (char)(l >> 24) ;
	p[1] = (char)(l >> 16) ;
	p[2] = (char)(l >> 8) ;
	p[3] = (char)(l >> 0) ;
}