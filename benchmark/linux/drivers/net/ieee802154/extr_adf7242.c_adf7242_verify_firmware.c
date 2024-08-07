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
typedef  scalar_t__ const u8 ;
struct adf7242_local {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int PRAM_PAGESIZE ; 
 int /*<<< orphan*/  REG_PRAMPG ; 
 int /*<<< orphan*/  adf7242_read_fbuf (struct adf7242_local*,scalar_t__ const*,size_t,int) ; 
 int /*<<< orphan*/  adf7242_write_reg (struct adf7242_local*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  kfree (scalar_t__ const*) ; 
 scalar_t__* kmalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int adf7242_verify_firmware(struct adf7242_local *lp,
				   const u8 *data, size_t len)
{
#ifdef DEBUG
	int i, j;
	unsigned int page;
	u8 *buf = kmalloc(PRAM_PAGESIZE, GFP_KERNEL);

	if (!buf)
		return -ENOMEM;

	for (page = 0, i = len; i >= 0; i -= PRAM_PAGESIZE, page++) {
		size_t nb = (i >= PRAM_PAGESIZE) ? PRAM_PAGESIZE : i;

		adf7242_write_reg(lp, REG_PRAMPG, page);
		adf7242_read_fbuf(lp, buf, nb, false);

		for (j = 0; j < nb; j++) {
			if (buf[j] != data[page * PRAM_PAGESIZE + j]) {
				kfree(buf);
				return -EIO;
			}
		}
	}
	kfree(buf);
#endif
	return 0;
}