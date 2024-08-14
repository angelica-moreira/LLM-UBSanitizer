#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tmp ;
struct slice {int /*<<< orphan*/  nblocks; int /*<<< orphan*/  blkoff; } ;
struct parsed_partitions {char* name; int limit; int /*<<< orphan*/  pp_buf; } ;
struct TYPE_4__ {int /*<<< orphan*/  ios_slcblk; int /*<<< orphan*/  ios_slccnt; } ;
struct TYPE_3__ {int /*<<< orphan*/  vid_mac; } ;
struct dkblk0 {TYPE_2__ dk_ios; TYPE_1__ dk_vid; } ;
typedef  int /*<<< orphan*/  Sector ;

/* Variables and functions */
 int /*<<< orphan*/  PAGE_SIZE ; 
 int be16_to_cpu (int /*<<< orphan*/ ) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  put_dev_sector (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  put_partition (struct parsed_partitions*,int,int,int) ; 
 unsigned char* read_part_sector (struct parsed_partitions*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,...) ; 
 int /*<<< orphan*/  strlcat (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ) ; 

int sysv68_partition(struct parsed_partitions *state)
{
	int i, slices;
	int slot = 1;
	Sector sect;
	unsigned char *data;
	struct dkblk0 *b;
	struct slice *slice;
	char tmp[64];

	data = read_part_sector(state, 0, &sect);
	if (!data)
		return -1;

	b = (struct dkblk0 *)data;
	if (memcmp(b->dk_vid.vid_mac, "MOTOROLA", sizeof(b->dk_vid.vid_mac))) {
		put_dev_sector(sect);
		return 0;
	}
	slices = be16_to_cpu(b->dk_ios.ios_slccnt);
	i = be32_to_cpu(b->dk_ios.ios_slcblk);
	put_dev_sector(sect);

	data = read_part_sector(state, i, &sect);
	if (!data)
		return -1;

	slices -= 1; /* last slice is the whole disk */
	snprintf(tmp, sizeof(tmp), "sysV68: %s(s%u)", state->name, slices);
	strlcat(state->pp_buf, tmp, PAGE_SIZE);
	slice = (struct slice *)data;
	for (i = 0; i < slices; i++, slice++) {
		if (slot == state->limit)
			break;
		if (be32_to_cpu(slice->nblocks)) {
			put_partition(state, slot,
				be32_to_cpu(slice->blkoff),
				be32_to_cpu(slice->nblocks));
			snprintf(tmp, sizeof(tmp), "(s%u)", i);
			strlcat(state->pp_buf, tmp, PAGE_SIZE);
		}
		slot++;
	}
	strlcat(state->pp_buf, "\n", PAGE_SIZE);
	put_dev_sector(sect);
	return 1;
}