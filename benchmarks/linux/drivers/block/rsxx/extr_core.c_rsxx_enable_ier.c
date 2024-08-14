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
struct rsxx_cardinfo {scalar_t__ regmap; int /*<<< orphan*/  ier_mask; int /*<<< orphan*/  eeh_state; int /*<<< orphan*/  halt; } ;

/* Variables and functions */
 scalar_t__ IER ; 
 int /*<<< orphan*/  __enable_intr (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  iowrite32 (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 

void rsxx_enable_ier(struct rsxx_cardinfo *card, unsigned int intr)
{
	if (unlikely(card->halt) ||
	    unlikely(card->eeh_state))
		return;

	__enable_intr(&card->ier_mask, intr);
	iowrite32(card->ier_mask, card->regmap + IER);
}