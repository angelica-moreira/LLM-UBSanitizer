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
struct nvmet_fc_tgt_assoc {int /*<<< orphan*/  ref; } ;

/* Variables and functions */
 int kref_get_unless_zero (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int
nvmet_fc_tgt_a_get(struct nvmet_fc_tgt_assoc *assoc)
{
	return kref_get_unless_zero(&assoc->ref);
}