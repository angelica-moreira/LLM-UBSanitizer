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
struct snd_ali {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALI_GLOBAL_CONTROL ; 
 int /*<<< orphan*/  ALI_REG (struct snd_ali*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ALI_SPDIF_OUT_CHANNEL ; 
 unsigned short ALI_SPDIF_OUT_SEL_PCM ; 
 unsigned short inw (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outw (unsigned short,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ali_enable_special_channel (struct snd_ali*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void snd_ali_enable_spdif_chnout(struct snd_ali *codec)
{
	unsigned short wVal;

	wVal  = inw(ALI_REG(codec, ALI_GLOBAL_CONTROL));
   	wVal &= ~ALI_SPDIF_OUT_SEL_PCM;
   	outw(wVal, ALI_REG(codec, ALI_GLOBAL_CONTROL));
/*
	wVal = inw(ALI_REG(codec, ALI_SPDIF_CS));
	if (flag & ALI_SPDIF_OUT_NON_PCM)
   		wVal |= 0x0002;
	else	
		wVal &= (~0x0002);
   	outw(wVal, ALI_REG(codec, ALI_SPDIF_CS));
*/
	snd_ali_enable_special_channel(codec, ALI_SPDIF_OUT_CHANNEL);
}