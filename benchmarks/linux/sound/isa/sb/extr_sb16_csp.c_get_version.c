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
struct snd_sb {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  command_seq (struct snd_sb*,unsigned char*,int) ; 
 int snd_sbdsp_get_byte (struct snd_sb*) ; 

__attribute__((used)) static int get_version(struct snd_sb *chip)
{
	unsigned char dsp_cmd[2];

	dsp_cmd[0] = 0x08;	/* SB_DSP_!something! */
	dsp_cmd[1] = 0x03;	/* get chip version id? */
	command_seq(chip, dsp_cmd, 2);

	return (snd_sbdsp_get_byte(chip));
}