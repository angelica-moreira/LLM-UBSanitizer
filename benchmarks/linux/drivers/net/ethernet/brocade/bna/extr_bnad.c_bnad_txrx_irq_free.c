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
struct bnad {int dummy; } ;
struct bna_intr_info {int /*<<< orphan*/ * idl; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
bnad_txrx_irq_free(struct bnad *bnad, struct bna_intr_info *intr_info)
{
	kfree(intr_info->idl);
	intr_info->idl = NULL;
}