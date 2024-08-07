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
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_2__ {scalar_t__ io_base; } ;

/* Variables and functions */
 TYPE_1__ fujitsu ; 
 int /*<<< orphan*/  inb (scalar_t__) ; 
 int /*<<< orphan*/  outb (int /*<<< orphan*/  const,scalar_t__) ; 

__attribute__((used)) static u8 fujitsu_read_register(const u8 addr)
{
	outb(addr, fujitsu.io_base);
	return inb(fujitsu.io_base + 4);
}