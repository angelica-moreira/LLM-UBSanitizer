#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  ide_hwif_t ;
struct TYPE_7__ {int pio_mode; int /*<<< orphan*/  name; } ;
typedef  TYPE_1__ ide_drive_t ;

/* Variables and functions */
 int XFER_PIO_0 ; 
 int /*<<< orphan*/  ht6560b_lock ; 
 int ht_pio2timings (TYPE_1__*,int const) ; 
 int /*<<< orphan*/  ht_set_prefetch (TYPE_1__*,int const) ; 
 scalar_t__ ide_get_drivedata (TYPE_1__*) ; 
 int /*<<< orphan*/  ide_set_drivedata (TYPE_1__*,void*) ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ,int const,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void ht6560b_set_pio_mode(ide_hwif_t *hwif, ide_drive_t *drive)
{
	unsigned long flags, config;
	const u8 pio = drive->pio_mode - XFER_PIO_0;
	u8 timing;
	
	switch (pio) {
	case 8:         /* set prefetch off */
	case 9:         /* set prefetch on */
		ht_set_prefetch(drive, pio & 1);
		return;
	}

	timing = ht_pio2timings(drive, pio);

	spin_lock_irqsave(&ht6560b_lock, flags);
	config = (unsigned long)ide_get_drivedata(drive);
	config &= 0xff00;
	config |= timing;
	ide_set_drivedata(drive, (void *)config);
	spin_unlock_irqrestore(&ht6560b_lock, flags);

#ifdef DEBUG
	printk("ht6560b: drive %s tuned to pio mode %#x timing=%#x\n", drive->name, pio, timing);
#endif
}