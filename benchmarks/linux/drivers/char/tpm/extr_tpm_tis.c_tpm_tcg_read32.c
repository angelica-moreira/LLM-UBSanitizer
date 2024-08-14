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
typedef  scalar_t__ u32 ;
struct tpm_tis_tcg_phy {scalar_t__ iobase; } ;
struct tpm_tis_data {int dummy; } ;

/* Variables and functions */
 scalar_t__ ioread32 (scalar_t__) ; 
 struct tpm_tis_tcg_phy* to_tpm_tis_tcg_phy (struct tpm_tis_data*) ; 

__attribute__((used)) static int tpm_tcg_read32(struct tpm_tis_data *data, u32 addr, u32 *result)
{
	struct tpm_tis_tcg_phy *phy = to_tpm_tis_tcg_phy(data);

	*result = ioread32(phy->iobase + addr);

	return 0;
}