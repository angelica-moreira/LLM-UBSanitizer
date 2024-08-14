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
typedef  scalar_t__ u16 ;
struct es1968 {TYPE_1__* card; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  IDR0_DATA_PORT ; 
 scalar_t__ __maestro_read (struct es1968*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __maestro_write (struct es1968*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void apu_data_set(struct es1968 *chip, u16 data)
{
	int i;
	for (i = 0; i < 1000; i++) {
		if (__maestro_read(chip, IDR0_DATA_PORT) == data)
			return;
		__maestro_write(chip, IDR0_DATA_PORT, data);
	}
	dev_dbg(chip->card->dev, "APU register set probably failed (Timeout)!\n");
}