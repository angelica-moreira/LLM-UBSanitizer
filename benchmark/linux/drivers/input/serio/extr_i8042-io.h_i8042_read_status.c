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
 int /*<<< orphan*/  I8042_STATUS_REG ; 
 int inb (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int i8042_read_status(void)
{
	return inb(I8042_STATUS_REG);
}