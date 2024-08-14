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
struct INFTLrecord {int nb_blocks; int lastEUN; int /*<<< orphan*/  nb_boot_blocks; int /*<<< orphan*/  LastFreeEUN; int /*<<< orphan*/  numfreeEUNs; int /*<<< orphan*/  firstEUN; int /*<<< orphan*/  numvunits; int /*<<< orphan*/  cylinders; int /*<<< orphan*/  sectors; int /*<<< orphan*/  heads; int /*<<< orphan*/  EraseSize; int /*<<< orphan*/ * PUtable; int /*<<< orphan*/ * VUtable; } ;

/* Variables and functions */
 int /*<<< orphan*/  pr_debug (char*,...) ; 

void INFTL_dumptables(struct INFTLrecord *s)
{
	int i;

	pr_debug("-------------------------------------------"
		"----------------------------------\n");

	pr_debug("VUtable[%d] ->", s->nb_blocks);
	for (i = 0; i < s->nb_blocks; i++) {
		if ((i % 8) == 0)
			pr_debug("\n%04x: ", i);
		pr_debug("%04x ", s->VUtable[i]);
	}

	pr_debug("\n-------------------------------------------"
		"----------------------------------\n");

	pr_debug("PUtable[%d-%d=%d] ->", s->firstEUN, s->lastEUN, s->nb_blocks);
	for (i = 0; i <= s->lastEUN; i++) {
		if ((i % 8) == 0)
			pr_debug("\n%04x: ", i);
		pr_debug("%04x ", s->PUtable[i]);
	}

	pr_debug("\n-------------------------------------------"
		"----------------------------------\n");

	pr_debug("INFTL ->\n"
		"  EraseSize       = %d\n"
		"  h/s/c           = %d/%d/%d\n"
		"  numvunits       = %d\n"
		"  firstEUN        = %d\n"
		"  lastEUN         = %d\n"
		"  numfreeEUNs     = %d\n"
		"  LastFreeEUN     = %d\n"
		"  nb_blocks       = %d\n"
		"  nb_boot_blocks  = %d",
		s->EraseSize, s->heads, s->sectors, s->cylinders,
		s->numvunits, s->firstEUN, s->lastEUN, s->numfreeEUNs,
		s->LastFreeEUN, s->nb_blocks, s->nb_boot_blocks);

	pr_debug("\n-------------------------------------------"
		"----------------------------------\n");
}