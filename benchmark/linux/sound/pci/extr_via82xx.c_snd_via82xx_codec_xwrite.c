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
struct via82xx {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  AC97 ; 
 int /*<<< orphan*/  VIAREG (struct via82xx*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outl (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void snd_via82xx_codec_xwrite(struct via82xx *chip, unsigned int val)
{
	outl(val, VIAREG(chip, AC97));
}