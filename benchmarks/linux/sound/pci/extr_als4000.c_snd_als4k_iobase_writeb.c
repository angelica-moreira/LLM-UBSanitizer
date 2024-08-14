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
typedef  int /*<<< orphan*/  u8 ;
typedef  enum als4k_iobase_t { ____Placeholder_als4k_iobase_t } als4k_iobase_t ;

/* Variables and functions */
 int /*<<< orphan*/  outb (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void snd_als4k_iobase_writeb(unsigned long iobase,
						enum als4k_iobase_t reg,
						u8 val)
{
	outb(val, iobase + reg);
}