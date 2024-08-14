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
struct intel_dvo_device {int dummy; } ;

/* Variables and functions */
 unsigned char SIL164_8_PD ; 
 int /*<<< orphan*/  SIL164_REG8 ; 
 int sil164_readb (struct intel_dvo_device*,int /*<<< orphan*/ ,unsigned char*) ; 
 int /*<<< orphan*/  sil164_writeb (struct intel_dvo_device*,int /*<<< orphan*/ ,unsigned char) ; 

__attribute__((used)) static void sil164_dpms(struct intel_dvo_device *dvo, bool enable)
{
	int ret;
	unsigned char ch;

	ret = sil164_readb(dvo, SIL164_REG8, &ch);
	if (ret == false)
		return;

	if (enable)
		ch |= SIL164_8_PD;
	else
		ch &= ~SIL164_8_PD;

	sil164_writeb(dvo, SIL164_REG8, ch);
	return;
}