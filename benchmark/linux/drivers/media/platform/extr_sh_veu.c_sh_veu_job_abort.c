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
struct sh_veu_dev {int aborting; } ;

/* Variables and functions */

__attribute__((used)) static void sh_veu_job_abort(void *priv)
{
	struct sh_veu_dev *veu = priv;

	/* Will cancel the transaction in the next interrupt handler */
	veu->aborting = true;
}