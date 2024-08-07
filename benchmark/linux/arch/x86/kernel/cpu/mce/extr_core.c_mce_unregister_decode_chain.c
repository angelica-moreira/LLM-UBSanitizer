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
struct notifier_block {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  num_notifiers ; 
 int /*<<< orphan*/  x86_mce_decoder_chain ; 

void mce_unregister_decode_chain(struct notifier_block *nb)
{
	atomic_dec(&num_notifiers);

	blocking_notifier_chain_unregister(&x86_mce_decoder_chain, nb);
}