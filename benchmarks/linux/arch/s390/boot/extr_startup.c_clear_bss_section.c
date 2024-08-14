#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int image_size; int /*<<< orphan*/  bss_size; scalar_t__ default_lma; } ;

/* Variables and functions */
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_1__ vmlinux ; 

__attribute__((used)) static void clear_bss_section(void)
{
	memset((void *)vmlinux.default_lma + vmlinux.image_size, 0, vmlinux.bss_size);
}