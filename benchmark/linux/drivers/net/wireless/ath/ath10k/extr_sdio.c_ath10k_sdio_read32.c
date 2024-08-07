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
struct sdio_func {int dummy; } ;
struct ath10k_sdio {struct sdio_func* func; } ;
struct ath10k {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATH10K_DBG_SDIO ; 
 int /*<<< orphan*/  ath10k_dbg (struct ath10k*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ath10k_sdio* ath10k_sdio_priv (struct ath10k*) ; 
 int /*<<< orphan*/  ath10k_warn (struct ath10k*,char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sdio_claim_host (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_readl (struct sdio_func*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  sdio_release_host (struct sdio_func*) ; 

__attribute__((used)) static int ath10k_sdio_read32(struct ath10k *ar, u32 addr, u32 *val)
{
	struct ath10k_sdio *ar_sdio = ath10k_sdio_priv(ar);
	struct sdio_func *func = ar_sdio->func;
	int ret;

	sdio_claim_host(func);
	*val = sdio_readl(func, addr, &ret);
	if (ret) {
		ath10k_warn(ar, "failed to read from address 0x%x: %d\n",
			    addr, ret);
		goto out;
	}

	ath10k_dbg(ar, ATH10K_DBG_SDIO, "sdio read32 addr 0x%x val 0x%x\n",
		   addr, *val);

out:
	sdio_release_host(func);

	return ret;
}