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
struct TYPE_2__ {int /*<<< orphan*/ * txq; } ;
struct ath_softc {TYPE_1__ tx; } ;

/* Variables and functions */
 int ATH9K_NUM_TX_QUEUES ; 
 int /*<<< orphan*/  ATH_TXQ_SETUP (struct ath_softc*,int) ; 
 int ath9k_has_pending_frames (struct ath_softc*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static bool ath9k_has_tx_pending(struct ath_softc *sc,
				 bool sw_pending)
{
	int i, npend = 0;

	for (i = 0; i < ATH9K_NUM_TX_QUEUES; i++) {
		if (!ATH_TXQ_SETUP(sc, i))
			continue;

		npend = ath9k_has_pending_frames(sc, &sc->tx.txq[i],
						 sw_pending);
		if (npend)
			break;
	}

	return !!npend;
}