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
struct sh_rtc {int periodic_freq; int /*<<< orphan*/  rtc_dev; scalar_t__ regbase; } ;

/* Variables and functions */
 int PF_COUNT ; 
 int PF_HP ; 
 scalar_t__ RCR2 ; 
 unsigned int RCR2_PEF ; 
 int RTC_IRQF ; 
 int RTC_PF ; 
 unsigned int readb (scalar_t__) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  writeb (unsigned int,scalar_t__) ; 

__attribute__((used)) static int __sh_rtc_periodic(struct sh_rtc *rtc)
{
	unsigned int tmp, pending;

	tmp = readb(rtc->regbase + RCR2);
	pending = tmp & RCR2_PEF;
	tmp &= ~RCR2_PEF;
	writeb(tmp, rtc->regbase + RCR2);

	if (!pending)
		return 0;

	/* Half period enabled than one skipped and the next notified */
	if ((rtc->periodic_freq & PF_HP) && (rtc->periodic_freq & PF_COUNT))
		rtc->periodic_freq &= ~PF_COUNT;
	else {
		if (rtc->periodic_freq & PF_HP)
			rtc->periodic_freq |= PF_COUNT;
		rtc_update_irq(rtc->rtc_dev, 1, RTC_PF | RTC_IRQF);
	}

	return pending;
}