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
typedef  int /*<<< orphan*/  tmp ;
struct unixware_slice {scalar_t__ s_label; int /*<<< orphan*/  nr_sects; int /*<<< orphan*/  start_sect; } ;
struct TYPE_2__ {struct unixware_slice* v_slice; int /*<<< orphan*/  v_magic; } ;
struct unixware_disklabel {TYPE_1__ vtoc; int /*<<< orphan*/  d_magic; } ;
struct parsed_partitions {char* name; scalar_t__ next; scalar_t__ limit; int /*<<< orphan*/  pp_buf; } ;
typedef  scalar_t__ sector_t ;
typedef  int /*<<< orphan*/  Sector ;

/* Variables and functions */
 int /*<<< orphan*/  BDEVNAME_SIZE ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 scalar_t__ UNIXWARE_DISKMAGIC ; 
 scalar_t__ UNIXWARE_DISKMAGIC2 ; 
 scalar_t__ UNIXWARE_FS_UNUSED ; 
 int UNIXWARE_NUMSLICE ; 
 scalar_t__ le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_dev_sector (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_partition (struct parsed_partitions*,int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 struct unixware_disklabel* read_part_sector (struct parsed_partitions*,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,int) ; 
 int /*<<< orphan*/  strlcat (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void parse_unixware(struct parsed_partitions *state,
			   sector_t offset, sector_t size, int origin)
{
#ifdef CONFIG_UNIXWARE_DISKLABEL
	Sector sect;
	struct unixware_disklabel *l;
	struct unixware_slice *p;

	l = read_part_sector(state, offset + 29, &sect);
	if (!l)
		return;
	if (le32_to_cpu(l->d_magic) != UNIXWARE_DISKMAGIC ||
	    le32_to_cpu(l->vtoc.v_magic) != UNIXWARE_DISKMAGIC2) {
		put_dev_sector(sect);
		return;
	}
	{
		char tmp[1 + BDEVNAME_SIZE + 10 + 12 + 1];

		snprintf(tmp, sizeof(tmp), " %s%d: <unixware:", state->name, origin);
		strlcat(state->pp_buf, tmp, PAGE_SIZE);
	}
	p = &l->vtoc.v_slice[1];
	/* I omit the 0th slice as it is the same as whole disk. */
	while (p - &l->vtoc.v_slice[0] < UNIXWARE_NUMSLICE) {
		if (state->next == state->limit)
			break;

		if (p->s_label != UNIXWARE_FS_UNUSED)
			put_partition(state, state->next++,
				      le32_to_cpu(p->start_sect),
				      le32_to_cpu(p->nr_sects));
		p++;
	}
	put_dev_sector(sect);
	strlcat(state->pp_buf, " >\n", PAGE_SIZE);
#endif
}