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
typedef  int /*<<< orphan*/  u_char ;
typedef  scalar_t__ u32 ;
struct TYPE_4__ {int options; } ;
struct TYPE_3__ {int /*<<< orphan*/  gpmc_prefetch_status; } ;
struct omap_nand_info {int buf_len; TYPE_2__ nand; int /*<<< orphan*/  gpmc_cs; TYPE_1__ reg; int /*<<< orphan*/  comp; int /*<<< orphan*/  gpmc_irq_fifo; int /*<<< orphan*/  gpmc_irq_count; int /*<<< orphan*/ * buf; int /*<<< orphan*/  iomode; } ;
struct nand_chip {int dummy; } ;
struct mtd_info {int oobsize; } ;

/* Variables and functions */
 int NAND_BUSWIDTH_16 ; 
 int /*<<< orphan*/  OMAP_NAND_IO_WRITE ; 
 int /*<<< orphan*/  OMAP_NAND_TIMEOUT_MS ; 
 int PREFETCH_FIFOTHRESHOLD_MAX ; 
 scalar_t__ PREFETCH_STATUS_COUNT (scalar_t__) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  enable_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 unsigned long loops_per_jiffy ; 
 unsigned long msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 struct omap_nand_info* mtd_to_omap (struct mtd_info*) ; 
 struct mtd_info* nand_to_mtd (struct nand_chip*) ; 
 int omap_prefetch_enable (int /*<<< orphan*/ ,int,int,int,int,struct omap_nand_info*) ; 
 int /*<<< orphan*/  omap_prefetch_reset (int /*<<< orphan*/ ,struct omap_nand_info*) ; 
 int /*<<< orphan*/  omap_write_buf16 (struct mtd_info*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  omap_write_buf8 (struct mtd_info*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  omap_write_buf_pref (struct nand_chip*,int /*<<< orphan*/  const*,int) ; 
 scalar_t__ readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wait_for_completion (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void omap_write_buf_irq_pref(struct nand_chip *chip, const u_char *buf,
				    int len)
{
	struct mtd_info *mtd = nand_to_mtd(chip);
	struct omap_nand_info *info = mtd_to_omap(mtd);
	int ret = 0;
	unsigned long tim, limit;
	u32 val;

	if (len <= mtd->oobsize) {
		omap_write_buf_pref(chip, buf, len);
		return;
	}

	info->iomode = OMAP_NAND_IO_WRITE;
	info->buf = (u_char *) buf;
	init_completion(&info->comp);

	/* configure and start prefetch transfer : size=24 */
	ret = omap_prefetch_enable(info->gpmc_cs,
		(PREFETCH_FIFOTHRESHOLD_MAX * 3) / 8, 0x0, len, 0x1, info);
	if (ret)
		/* PFPW engine is busy, use cpu copy method */
		goto out_copy;

	info->buf_len = len;

	enable_irq(info->gpmc_irq_count);
	enable_irq(info->gpmc_irq_fifo);

	/* waiting for write to complete */
	wait_for_completion(&info->comp);

	/* wait for data to flushed-out before reset the prefetch */
	tim = 0;
	limit = (loops_per_jiffy *  msecs_to_jiffies(OMAP_NAND_TIMEOUT_MS));
	do {
		val = readl(info->reg.gpmc_prefetch_status);
		val = PREFETCH_STATUS_COUNT(val);
		cpu_relax();
	} while (val && (tim++ < limit));

	/* disable and stop the PFPW engine */
	omap_prefetch_reset(info->gpmc_cs, info);
	return;

out_copy:
	if (info->nand.options & NAND_BUSWIDTH_16)
		omap_write_buf16(mtd, buf, len);
	else
		omap_write_buf8(mtd, buf, len);
}