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
struct omap_aes_dev {int /*<<< orphan*/  total; } ;

/* Variables and functions */
 int /*<<< orphan*/  omap_aes_dma_stop (struct omap_aes_dev*) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ) ; 

int omap_aes_crypt_dma_stop(struct omap_aes_dev *dd)
{
	pr_debug("total: %d\n", dd->total);

	omap_aes_dma_stop(dd);


	return 0;
}