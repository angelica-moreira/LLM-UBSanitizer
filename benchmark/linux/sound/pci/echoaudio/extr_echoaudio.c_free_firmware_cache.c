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
struct echoaudio {TYPE_1__* card; scalar_t__* fw_cache; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  release_firmware (scalar_t__) ; 

__attribute__((used)) static void free_firmware_cache(struct echoaudio *chip)
{
#ifdef CONFIG_PM_SLEEP
	int i;

	for (i = 0; i < 8 ; i++)
		if (chip->fw_cache[i]) {
			release_firmware(chip->fw_cache[i]);
			dev_dbg(chip->card->dev, "release_firmware(%d)\n", i);
		}

#endif
}