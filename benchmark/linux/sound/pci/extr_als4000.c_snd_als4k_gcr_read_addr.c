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
typedef  enum als4k_gcr_t { ____Placeholder_als4k_gcr_t } als4k_gcr_t ;

/* Variables and functions */
 int /*<<< orphan*/  ALS4K_IOB_0C_GCR_INDEX ; 
 int /*<<< orphan*/  ALS4K_IOD_08_GCR_DATA ; 
 int /*<<< orphan*/  snd_als4k_iobase_readl (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_als4k_iobase_writeb (unsigned long,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline u32 snd_als4k_gcr_read_addr(unsigned long iobase,
						 enum als4k_gcr_t reg)
{
	/* SPECS_PAGE: 37/38 */
	snd_als4k_iobase_writeb(iobase, ALS4K_IOB_0C_GCR_INDEX, reg);
	return snd_als4k_iobase_readl(iobase, ALS4K_IOD_08_GCR_DATA);
}