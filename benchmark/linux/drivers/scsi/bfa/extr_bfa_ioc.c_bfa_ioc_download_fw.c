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
typedef  scalar_t__ u32 ;
struct TYPE_2__ {int /*<<< orphan*/  smem_page_start; int /*<<< orphan*/  host_page_num_fn; int /*<<< orphan*/  smem_pg0; } ;
struct bfa_ioc_s {TYPE_1__ ioc_regs; int /*<<< orphan*/  port1_mode; int /*<<< orphan*/  port0_mode; int /*<<< orphan*/  asic_mode; int /*<<< orphan*/  asic_gen; } ;
typedef  scalar_t__ bfa_status_t ;

/* Variables and functions */
 int /*<<< orphan*/  BFA_IOC_FLASH_CHUNK_ADDR (scalar_t__) ; 
 scalar_t__ BFA_IOC_FLASH_CHUNK_NO (scalar_t__) ; 
 size_t BFA_IOC_FLASH_OFFSET_IN_CHUNK (scalar_t__) ; 
 scalar_t__ BFA_STATUS_OK ; 
 int BFI_FLASH_CHUNK_SZ_WORDS ; 
 int BFI_FLASH_IMAGE_SZ ; 
 scalar_t__ BFI_FWBOOT_DEVMODE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ BFI_FWBOOT_DEVMODE_OFF ; 
 scalar_t__ BFI_FWBOOT_ENV_OFF ; 
 scalar_t__ BFI_FWBOOT_ENV_OS ; 
 scalar_t__ BFI_FWBOOT_TYPE_FLASH ; 
 scalar_t__ BFI_FWBOOT_TYPE_NORMAL ; 
 scalar_t__ BFI_FWBOOT_TYPE_OFF ; 
 scalar_t__ PSS_SMEM_PGNUM (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ PSS_SMEM_PGOFF (scalar_t__) ; 
 scalar_t__* bfa_cb_image_get_chunk (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ bfa_cb_image_get_size (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bfa_ioc_asic_gen (struct bfa_ioc_s*) ; 
 scalar_t__ bfa_ioc_flash_img_get_chnk (struct bfa_ioc_s*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int /*<<< orphan*/  bfa_mem_write (int /*<<< orphan*/ ,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  bfa_trc (struct bfa_ioc_s*,scalar_t__) ; 
 scalar_t__ swab32 (scalar_t__) ; 
 int /*<<< orphan*/  writel (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bfa_status_t
bfa_ioc_download_fw(struct bfa_ioc_s *ioc, u32 boot_type,
		    u32 boot_env)
{
	u32 *fwimg;
	u32 pgnum, pgoff;
	u32 loff = 0;
	u32 chunkno = 0;
	u32 i;
	u32 asicmode;
	u32 fwimg_size;
	u32 fwimg_buf[BFI_FLASH_CHUNK_SZ_WORDS];
	bfa_status_t status;

	if (boot_env == BFI_FWBOOT_ENV_OS &&
		boot_type == BFI_FWBOOT_TYPE_FLASH) {
		fwimg_size = BFI_FLASH_IMAGE_SZ/sizeof(u32);

		status = bfa_ioc_flash_img_get_chnk(ioc,
			BFA_IOC_FLASH_CHUNK_ADDR(chunkno), fwimg_buf);
		if (status != BFA_STATUS_OK)
			return status;

		fwimg = fwimg_buf;
	} else {
		fwimg_size = bfa_cb_image_get_size(bfa_ioc_asic_gen(ioc));
		fwimg = bfa_cb_image_get_chunk(bfa_ioc_asic_gen(ioc),
					BFA_IOC_FLASH_CHUNK_ADDR(chunkno));
	}

	bfa_trc(ioc, fwimg_size);


	pgnum = PSS_SMEM_PGNUM(ioc->ioc_regs.smem_pg0, loff);
	pgoff = PSS_SMEM_PGOFF(loff);

	writel(pgnum, ioc->ioc_regs.host_page_num_fn);

	for (i = 0; i < fwimg_size; i++) {

		if (BFA_IOC_FLASH_CHUNK_NO(i) != chunkno) {
			chunkno = BFA_IOC_FLASH_CHUNK_NO(i);

			if (boot_env == BFI_FWBOOT_ENV_OS &&
				boot_type == BFI_FWBOOT_TYPE_FLASH) {
				status = bfa_ioc_flash_img_get_chnk(ioc,
					BFA_IOC_FLASH_CHUNK_ADDR(chunkno),
					fwimg_buf);
				if (status != BFA_STATUS_OK)
					return status;

				fwimg = fwimg_buf;
			} else {
				fwimg = bfa_cb_image_get_chunk(
					bfa_ioc_asic_gen(ioc),
					BFA_IOC_FLASH_CHUNK_ADDR(chunkno));
			}
		}

		/*
		 * write smem
		 */
		bfa_mem_write(ioc->ioc_regs.smem_page_start, loff,
			      fwimg[BFA_IOC_FLASH_OFFSET_IN_CHUNK(i)]);

		loff += sizeof(u32);

		/*
		 * handle page offset wrap around
		 */
		loff = PSS_SMEM_PGOFF(loff);
		if (loff == 0) {
			pgnum++;
			writel(pgnum, ioc->ioc_regs.host_page_num_fn);
		}
	}

	writel(PSS_SMEM_PGNUM(ioc->ioc_regs.smem_pg0, 0),
			ioc->ioc_regs.host_page_num_fn);

	/*
	 * Set boot type, env and device mode at the end.
	 */
	if (boot_env == BFI_FWBOOT_ENV_OS &&
		boot_type == BFI_FWBOOT_TYPE_FLASH) {
		boot_type = BFI_FWBOOT_TYPE_NORMAL;
	}
	asicmode = BFI_FWBOOT_DEVMODE(ioc->asic_gen, ioc->asic_mode,
				ioc->port0_mode, ioc->port1_mode);
	bfa_mem_write(ioc->ioc_regs.smem_page_start, BFI_FWBOOT_DEVMODE_OFF,
			swab32(asicmode));
	bfa_mem_write(ioc->ioc_regs.smem_page_start, BFI_FWBOOT_TYPE_OFF,
			swab32(boot_type));
	bfa_mem_write(ioc->ioc_regs.smem_page_start, BFI_FWBOOT_ENV_OFF,
			swab32(boot_env));
	return BFA_STATUS_OK;
}