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
 int /*<<< orphan*/  R_HEAD ; 
 int /*<<< orphan*/  R_SECTOR ; 
 int /*<<< orphan*/  R_SIZECODE ; 
 int /*<<< orphan*/  R_TRACK ; 
 int /*<<< orphan*/  pr_cont (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void tell_sector(void)
{
	pr_cont(": track %d, head %d, sector %d, size %d",
		R_TRACK, R_HEAD, R_SECTOR, R_SIZECODE);
}