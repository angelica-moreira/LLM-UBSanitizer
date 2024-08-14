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
struct max8925_rtc_info {int /*<<< orphan*/  rtc_dev; int /*<<< orphan*/  rtc; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  MAX8925_ALARM0_CNTL ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
 int /*<<< orphan*/  max8925_set_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtc_update_irq (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static irqreturn_t rtc_update_handler(int irq, void *data)
{
	struct max8925_rtc_info *info = (struct max8925_rtc_info *)data;

	/* disable ALARM0 except for 1SEC alarm */
	max8925_set_bits(info->rtc, MAX8925_ALARM0_CNTL, 0x7f, 0);
	rtc_update_irq(info->rtc_dev, 1, RTC_IRQF | RTC_AF);
	return IRQ_HANDLED;
}