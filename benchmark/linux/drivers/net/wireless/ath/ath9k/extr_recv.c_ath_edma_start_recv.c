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
struct ath_softc {TYPE_1__* cur_chan; int /*<<< orphan*/  sc_ah; } ;
struct TYPE_2__ {int /*<<< orphan*/  offchannel; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATH9K_RX_QUEUE_HP ; 
 int /*<<< orphan*/  ATH9K_RX_QUEUE_LP ; 
 int /*<<< orphan*/  ath9k_hw_rxena (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath9k_hw_startpcureceive (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath_opmode_init (struct ath_softc*) ; 
 int /*<<< orphan*/  ath_rx_addbuffer_edma (struct ath_softc*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ath_edma_start_recv(struct ath_softc *sc)
{
	ath9k_hw_rxena(sc->sc_ah);
	ath_rx_addbuffer_edma(sc, ATH9K_RX_QUEUE_HP);
	ath_rx_addbuffer_edma(sc, ATH9K_RX_QUEUE_LP);
	ath_opmode_init(sc);
	ath9k_hw_startpcureceive(sc->sc_ah, sc->cur_chan->offchannel);
}