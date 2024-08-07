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
struct snd_harmony {unsigned int iobase; } ;

/* Variables and functions */
 int /*<<< orphan*/  __raw_writel (unsigned long,unsigned int) ; 

__attribute__((used)) static inline void
harmony_write(struct snd_harmony *h, unsigned r, unsigned long v)
{
	__raw_writel(v, h->iobase + r);
}