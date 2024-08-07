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
struct saa7134_dev {int dummy; } ;
typedef  enum tda18271_mode { ____Placeholder_tda18271_mode } tda18271_mode ;

/* Variables and functions */
 int EINVAL ; 
 int SAA7134_GPIO_GPMODE0 ; 
 int SAA7134_GPIO_GPSTATUS0 ; 
#define  TDA18271_ANALOG 129 
#define  TDA18271_DIGITAL 128 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  saa_writel (int,int) ; 

__attribute__((used)) static inline int saa7134_kworld_sbtvd_toggle_agc(struct saa7134_dev *dev,
						  enum tda18271_mode mode)
{
	/* toggle AGC switch through GPIO 27 */
	switch (mode) {
	case TDA18271_ANALOG:
		saa_writel(SAA7134_GPIO_GPMODE0 >> 2, 0x4000);
		saa_writel(SAA7134_GPIO_GPSTATUS0 >> 2, 0x4000);
		msleep(20);
		break;
	case TDA18271_DIGITAL:
		saa_writel(SAA7134_GPIO_GPMODE0 >> 2, 0x14000);
		saa_writel(SAA7134_GPIO_GPSTATUS0 >> 2, 0x14000);
		msleep(20);
		saa_writel(SAA7134_GPIO_GPMODE0 >> 2, 0x54000);
		saa_writel(SAA7134_GPIO_GPSTATUS0 >> 2, 0x54000);
		msleep(30);
		break;
	default:
		return -EINVAL;
	}
	return 0;
}