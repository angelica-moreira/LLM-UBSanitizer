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
struct mmc_omap_host {int buffer_bytes_left; scalar_t__ sg_idx; scalar_t__ sg_len; int total_bytes_left; int buffer; scalar_t__ virt_base; TYPE_1__* data; } ;
struct TYPE_2__ {int bytes_xfered; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  DATA ; 
 int DIV_ROUND_UP (int,int) ; 
 scalar_t__ OMAP_MMC_REG (struct mmc_omap_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_readsw (scalar_t__,int,int) ; 
 int /*<<< orphan*/  __raw_writesw (scalar_t__,int,int) ; 
 int /*<<< orphan*/  mmc_omap_sg_to_buf (struct mmc_omap_host*) ; 

__attribute__((used)) static void
mmc_omap_xfer_data(struct mmc_omap_host *host, int write)
{
	int n, nwords;

	if (host->buffer_bytes_left == 0) {
		host->sg_idx++;
		BUG_ON(host->sg_idx == host->sg_len);
		mmc_omap_sg_to_buf(host);
	}
	n = 64;
	if (n > host->buffer_bytes_left)
		n = host->buffer_bytes_left;

	/* Round up to handle odd number of bytes to transfer */
	nwords = DIV_ROUND_UP(n, 2);

	host->buffer_bytes_left -= n;
	host->total_bytes_left -= n;
	host->data->bytes_xfered += n;

	if (write) {
		__raw_writesw(host->virt_base + OMAP_MMC_REG(host, DATA),
			      host->buffer, nwords);
	} else {
		__raw_readsw(host->virt_base + OMAP_MMC_REG(host, DATA),
			     host->buffer, nwords);
	}

	host->buffer += nwords;
}