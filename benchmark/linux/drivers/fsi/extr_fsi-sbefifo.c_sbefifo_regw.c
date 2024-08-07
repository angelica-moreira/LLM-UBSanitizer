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
typedef  int /*<<< orphan*/  u32 ;
struct sbefifo {int /*<<< orphan*/  fsi_dev; } ;
typedef  int /*<<< orphan*/  raw_word ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  cpu_to_be32 (int /*<<< orphan*/ ) ; 
 int fsi_device_write (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int sbefifo_regw(struct sbefifo *sbefifo, int reg, u32 word)
{
	__be32 raw_word = cpu_to_be32(word);

	return fsi_device_write(sbefifo->fsi_dev, reg, &raw_word,
				sizeof(raw_word));
}