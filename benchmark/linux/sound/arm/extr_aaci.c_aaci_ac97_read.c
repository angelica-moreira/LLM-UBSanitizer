#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct snd_ac97 {int num; struct aaci* private_data; } ;
struct aaci {int /*<<< orphan*/  ac97_sem; TYPE_1__* dev; scalar_t__ base; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 scalar_t__ AACI_SL1RX ; 
 scalar_t__ AACI_SL1TX ; 
 scalar_t__ AACI_SL2RX ; 
 scalar_t__ AACI_SLFR ; 
 int FRAME_PERIOD_US ; 
 int SLFR_1RXV ; 
 int SLFR_1TXB ; 
 int SLFR_2RXV ; 
 int /*<<< orphan*/  aaci_ac97_select_codec (struct aaci*,struct snd_ac97*) ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  writel (unsigned short,scalar_t__) ; 

__attribute__((used)) static unsigned short aaci_ac97_read(struct snd_ac97 *ac97, unsigned short reg)
{
	struct aaci *aaci = ac97->private_data;
	int timeout, retries = 10;
	u32 v;

	if (ac97->num >= 4)
		return ~0;

	mutex_lock(&aaci->ac97_sem);

	aaci_ac97_select_codec(aaci, ac97);

	/*
	 * Write the register address to slot 1.
	 */
	writel((reg << 12) | (1 << 19), aaci->base + AACI_SL1TX);

	/* Initially, wait one frame period */
	udelay(FRAME_PERIOD_US);

	/* And then wait an additional eight frame periods for it to be sent */
	timeout = FRAME_PERIOD_US * 8;
	do {
		udelay(1);
		v = readl(aaci->base + AACI_SLFR);
	} while ((v & SLFR_1TXB) && --timeout);

	if (v & SLFR_1TXB) {
		dev_err(&aaci->dev->dev, "timeout on slot 1 TX busy\n");
		v = ~0;
		goto out;
	}

	/* Now wait for the response frame */
	udelay(FRAME_PERIOD_US);

	/* And then wait an additional eight frame periods for data */
	timeout = FRAME_PERIOD_US * 8;
	do {
		udelay(1);
		cond_resched();
		v = readl(aaci->base + AACI_SLFR) & (SLFR_1RXV|SLFR_2RXV);
	} while ((v != (SLFR_1RXV|SLFR_2RXV)) && --timeout);

	if (v != (SLFR_1RXV|SLFR_2RXV)) {
		dev_err(&aaci->dev->dev, "timeout on RX valid\n");
		v = ~0;
		goto out;
	}

	do {
		v = readl(aaci->base + AACI_SL1RX) >> 12;
		if (v == reg) {
			v = readl(aaci->base + AACI_SL2RX) >> 4;
			break;
		} else if (--retries) {
			dev_warn(&aaci->dev->dev,
				 "ac97 read back fail.  retry\n");
			continue;
		} else {
			dev_warn(&aaci->dev->dev,
				"wrong ac97 register read back (%x != %x)\n",
				v, reg);
			v = ~0;
		}
	} while (retries);
 out:
	mutex_unlock(&aaci->ac97_sem);
	return v;
}