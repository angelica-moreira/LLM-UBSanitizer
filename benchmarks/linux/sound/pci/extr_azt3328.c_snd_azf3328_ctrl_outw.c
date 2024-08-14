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
typedef  int /*<<< orphan*/  u16 ;
struct snd_azf3328 {unsigned int ctrl_io; } ;

/* Variables and functions */
 int /*<<< orphan*/  outw (int /*<<< orphan*/ ,unsigned int) ; 

__attribute__((used)) static inline void
snd_azf3328_ctrl_outw(const struct snd_azf3328 *chip, unsigned reg, u16 value)
{
	outw(value, chip->ctrl_io + reg);
}