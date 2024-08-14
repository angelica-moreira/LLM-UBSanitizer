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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct if_spi_card {int dummy; } ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  __le32 ;

/* Variables and functions */
 int /*<<< orphan*/  le32_to_cpup (int /*<<< orphan*/ *) ; 
 int spu_read (struct if_spi_card*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int spu_read_u32(struct if_spi_card *card, u16 reg, u32 *val)
{
	__le32 buf;
	int err;

	err = spu_read(card, reg, (u8 *)&buf, sizeof(buf));
	if (!err)
		*val = le32_to_cpup(&buf);
	return err;
}