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
typedef  int u8 ;
struct btmrvl_sdio_card {TYPE_1__* reg; int /*<<< orphan*/  func; } ;
struct TYPE_2__ {int /*<<< orphan*/  card_status; } ;

/* Variables and functions */
 int /*<<< orphan*/  BT_ERR (char*,int) ; 
 int ETIMEDOUT ; 
 int MAX_POLL_TRIES ; 
 int sdio_readb (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static int btmrvl_sdio_poll_card_status(struct btmrvl_sdio_card *card, u8 bits)
{
	unsigned int tries;
	u8 status;
	int ret;

	for (tries = 0; tries < MAX_POLL_TRIES * 1000; tries++) {
		status = sdio_readb(card->func, card->reg->card_status,	&ret);
		if (ret)
			goto failed;
		if ((status & bits) == bits)
			return ret;

		udelay(1);
	}

	ret = -ETIMEDOUT;

failed:
	BT_ERR("FAILED! ret=%d", ret);

	return ret;
}