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
struct tmio_mmc_host {int bus_shift; scalar_t__ ctl; } ;

/* Variables and functions */
 int /*<<< orphan*/  iowrite32_rep (scalar_t__,int /*<<< orphan*/  const*,int) ; 

__attribute__((used)) static inline void sd_ctrl_write32_rep(struct tmio_mmc_host *host, int addr,
				       const u32 *buf, int count)
{
	iowrite32_rep(host->ctl + (addr << host->bus_shift), buf, count);
}