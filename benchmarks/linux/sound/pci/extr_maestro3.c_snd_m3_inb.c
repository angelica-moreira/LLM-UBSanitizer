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
struct snd_m3 {scalar_t__ iobase; } ;

/* Variables and functions */
 int /*<<< orphan*/  inb (scalar_t__) ; 

__attribute__((used)) static inline u8 snd_m3_inb(struct snd_m3 *chip, unsigned long reg)
{
	return inb(chip->iobase + reg);
}